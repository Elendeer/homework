#include <iostream>
#include <vector>

using namespace std;

class Page {
private:

	bool _is_in_memory;
	// if _is_in_memory is false, _block_no will be -1
	int _block_no;
	bool _is_modified;
	// if _is_in_memory is true, _position_in_disk will be -1
	int _position_in_disk;

	int _t;

public:
	Page(
		bool is_in_memory,
		int block_no,
		bool is_modified,
		int position_in_disk);
	~Page();

	bool isInMemory() const { return _is_in_memory; }
	int getBlockNo() const { return _block_no; }
	bool isModified() const { return _is_modified; }
	int getPositionInDisk() const { return _position_in_disk; }
	int getT() const { return _t; }

	void touch() { _t = 0; }
	void increase() { ++ _t; }

	void print() const;

	const Page & operator = (const Page & p);

	static void swap(Page & p1, Page & p2);
};

Page::Page(bool is_in_memory,
		int block_no,
		bool is_modified,
		int position_in_disk):
			_is_in_memory(is_in_memory),
			_block_no(block_no),
			_is_modified(is_modified),
			_position_in_disk(position_in_disk),
			_t(0)
			{}
Page::~Page() {}

void Page::print() const {
	cout << _is_in_memory << "\t" << _block_no << "\t"
		<< _is_modified << "\t" << _position_in_disk << endl;
}

const Page & Page::operator = (const Page & p) {
	_is_in_memory = p._is_in_memory;
	_block_no = p._block_no;
	_is_modified = p._is_modified;
	_position_in_disk = p._position_in_disk;

	return p;
}

void Page::swap(Page & p1, Page & p2) {
	Page tmp = p1;
	p1 = p2;
	p2 = tmp;
}

/*********************************************
*********************************************/

class Machine {
private:
	vector<Page> _page_table;

	// count times of page missing
	int _count;
	// number of opreation
	int _op_no;

public:
	Machine(vector<Page> page_table);
	~Machine();

	void Do(char oprator,
		int page_no_1, int offset_1,
		int page_no_2, int offset_2);

	void printPageTable() const;
};

Machine::Machine(vector<Page> page_table):
	_page_table(page_table), _count(0), _op_no(0) {
	}

Machine::~Machine() {}

void Machine::Do(char oprator,
	int page_no_1, int offset_1,
	int page_no_2, int offset_2) {

		if (!_page_table.at(page_no_1).isInMemory()) {
			cout << "page missing time: " << ++_count << endl;

			int idx = -1;
			for (int i = 0; i < _page_table.size(); ++ i ) {
				if (idx == -1 && _page_table.at(i).isInMemory())
					idx = i;
				if (_page_table.at(i).isInMemory() &&
					_page_table.at(i).getT() < idx)
						idx = i;
			}

			Page::swap(_page_table[idx], _page_table[page_no_1]);

			printPageTable();
		}
		if (!_page_table.at(page_no_2).isInMemory()) {
			cout << "page missing time: " << ++_count << endl;

			int idx = -1;
			for (int i = 0; i < _page_table.size(); ++ i ) {
				if (idx == -1 && _page_table.at(i).isInMemory())
					idx = i;
				if (_page_table.at(i).isInMemory() &&
					_page_table.at(i).getT() < idx)
						idx = i;
			}


			Page::swap(_page_table[idx], _page_table[page_no_2]);

			printPageTable();
		}
		_page_table[page_no_1].touch();
		_page_table[page_no_2].touch();

		int addr_1 =
			_page_table.at(page_no_1).getBlockNo() * 1024 + offset_1;
		int addr_2 =
			_page_table.at(page_no_2).getBlockNo() * 1024 + offset_2;

		cout << "operation " << _op_no << ": ("
			<< hex << addr_1 << "H)" << oprator << "("
			<< addr_2 << "H)" << endl << dec;


		++_op_no;

		for (Page & p : _page_table) {
			p.increase();
		}
	}



void Machine::printPageTable() const {
	cout << "PageNo\tisInMemory\tblockNo\tisModified\tpositionInDisk"
		<< endl;

	int num = 0;
	for (const Page & p : _page_table) {
		cout << num ++ << "\t";
		p.print();
	}
}

int main() {
	vector<Page> v;
	v.push_back(Page(true, 3, true, -1));
	v.push_back(Page(true, 4, true, -1));
	v.push_back(Page(true, 5, true, -1));
	v.push_back(Page(false, -1, true, 30));
	v.push_back(Page(false, -1, true, 25));
	v.push_back(Page(false, -1, true, 26));

	Machine m = Machine(v);
	m.Do('+', 0, 30, 2, 3);
	m.Do('-', 1, 50, 2, 5);
	m.Do('*', 2, 1, 5, 4);
	m.Do('/', 3, 7, 1, 31);


	return 0;
}
