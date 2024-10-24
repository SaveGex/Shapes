#include "Square.h"

Square::Square(string name, int A) : Shape::Shape(name), A{ A }, stmt{ nullptr } {

	int error = sqlite3_open(directory.c_str(), &this->DB);
	if (error != SQLITE_OK) {
		cerr << "DB can't open";
	}
}

string Square::Show() {
	cout << format("\nname:{}\nA,B,C,D {}cm", name, A);
	return format("\nname:{}\nA,B,C,D {}cm", name, A);
}

bool Square::Save() {

	string sql = "\
		CREATE TABLE IF NOT EXISTS " + name_table + "(\
		`ID` INTEGER PRIMARY KEY AUTOINCREMENT, \
		`NAME` TEXT,\
		`DATA` JSON);";

	int errors = sqlite3_exec(this->DB, sql.c_str(), NULL, 0, 0);

	json json_obj;
	json_obj["data"] = json::array();
	json_obj["data"].push_back(A);
	string jsonString = json_obj.dump();

	sql = "INSERT INTO " + name_table + " (NAME, DATA) VALUES(? , ?); ";
	errors = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, 0);
	if (errors != SQLITE_OK) {
		cerr << "error: " << sqlite3_errmsg(DB) << endl;
		return false;
	}

	sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, jsonString.c_str(), -1, SQLITE_TRANSIENT);

	if (sqlite3_step(stmt) != SQLITE_DONE) {
		cerr << "error when send the request: " << sqlite3_errmsg(DB);
		return false;
	}

	sqlite3_finalize(stmt);

	return true;

}

vector<Shape*> Square::Load() {

	vector<Shape*> Shapes_vector;
	json json_obj;
	json_obj["data"] = json::array();
	json_obj["names"] = json::array();
	string jsonString;
	string sql = "SELECT * FROM " + name_table + ';';


	if (sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {

		while (sqlite3_step(stmt) == SQLITE_ROW) {
			string name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
			const unsigned char* jsonText = sqlite3_column_text(stmt, 2);
			string jsonString(reinterpret_cast<const char*>(jsonText));

			try {
				json parsedJson = json::parse(jsonString);
				int value = parsedJson["data"][0].get<int>();

				Square* obj = new Square(name, value);
				Shapes_vector.push_back(obj);
			}
			catch (json::parse_error& e) {
				cerr << "JSON parsing error: " << e.what() << std::endl;
			}
		}
	}

	sqlite3_finalize(stmt);
	return Shapes_vector;
}
