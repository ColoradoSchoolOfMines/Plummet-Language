#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

typedef enum {
	TYPE_INT,
	TYPE_STRING,
} Type;

class Symbol {
	private:
		string name;
		Type type;

	public:
		Symbol(string name, Type type) {
			this->name = name;
			this->type = type;
		}

		string getName() {
			return name;
		}

		Type getType() {
			return type;
		}

		void prettyPrint() {
			cout << "Symbol: " << name << " Type: " << type << endl;
		}
};

class Scope {
	private:
		unordered_map<string, Symbol> table;

	protected:
		Scope *parent;

	public:
		Scope(Scope *previous = nullptr) {
			parent = previous;
		}

		void add(string id, Symbol symbol) {
			table.insert({id, symbol});
		}

		Symbol* get(string id) {
			for (Scope *scope = this; scope != nullptr; scope = scope->parent) {
				auto found = scope->table.find(id);

				if (found != scope->table.end()) {
					return &found->second;
				}
			}

			return nullptr;
		}

		void prettyPrint() {
			if (parent != nullptr) {
				parent->prettyPrint();
			}

			for (auto it = table.begin(); it != table.end(); it++) {
				it->second.prettyPrint();
			}
		}
};

int main() {
}
