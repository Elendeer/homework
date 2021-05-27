/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2021-04-26 19:29:57
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-05-27 20:46:57
 * @Description  :
*********************************************/

#include <iostream>
#include <list>
#include <string>

using namespace std;

// Used for record the allocted memory
class MemoryRecord {
private:
    double _start_address, _length;

public:
    MemoryRecord(double start_address = -1, double length = -1);
    ~MemoryRecord();

    double getStartAddress() const;
    double getLength() const;
};

MemoryRecord::MemoryRecord(double start_address, double length) :
    _start_address(start_address), _length(length) {}

MemoryRecord::~MemoryRecord() {}

double MemoryRecord::getStartAddress() const {
    return _start_address;
}
double MemoryRecord::getLength() const {
    return _length;
}

// ===== =====

class Partition {
private:
    double _no, _size, _start_address;
    double _remained, _allocated;

public:
    Partition(
        double no, double start_address,
        double  size, double allocated = 0);

    Partition(const Partition & obj) = default;
    ~Partition();

    double getNo() const ;
    double getSize() const ;
    double getStartAddress() const ;

    double getAllocated() const;
    double getRemained() const;

    void allocate(double size);

    void print() const;
};

Partition::Partition(
    double no, double start_address, double size, double allocated) :
    _no(no), _size(size), _start_address(start_address),
    _allocated(allocated) {
        _remained = _size - _allocated;
    }

Partition::~Partition() {}

double Partition::getNo() const {
    return _no;
}
double Partition::getSize() const {
    return _size;
}
double Partition::getStartAddress() const {
    return _start_address;
}

double Partition::getAllocated() const {
    return _allocated;
}
double Partition::getRemained() const {
    return _remained;
}

void Partition::allocate(double size) {
    if (size + _allocated > _size) {
        cout << "allocating error" << endl;
        return ;
    }

    _allocated += size;
    _remained -= size;
}

void Partition::print() const {
    cout << "NO: " << _no
        << "\tStartAddress: " << _start_address
        << "\tSize: " << _size
        << "\tAllocated: " << _allocated << endl;
}

// ===== =====

class PartitionTable {
private:
    list<Partition> _list;

public:
    PartitionTable(list<Partition> & list);
    ~PartitionTable();

    MemoryRecord allocate(string process_name, double required_size);

    void print() const ;
};

PartitionTable::PartitionTable(list<Partition> & list):
    _list(list) {
        _list.sort([](Partition pa, Partition pb){
            return pa.getSize() < pb.getSize();
        });
    }
PartitionTable::~PartitionTable() {}

MemoryRecord PartitionTable::allocate(
    string process_name, double required_size) {
        int remained_size = _list.front().getRemained();
        list<Partition>::iterator i = _list.begin();

        if (remained_size >= required_size) {
            if (remained_size - required_size < 0.3) {
                MemoryRecord mr = MemoryRecord(
                    i->getStartAddress() + i->getAllocated(),
                    i->getRemained());

                i->allocate(remained_size);

                cout << process_name
                    << ": allocating succeed" << endl;
                return mr;
            }
            else {
                MemoryRecord mr = MemoryRecord(
                    i->getStartAddress() + i->getAllocated(),
                    required_size);

                i->allocate(required_size);

                cout << process_name
                    << ": allocating succeed" << endl;
                return mr;
            }
        }

        cout << process_name << ": allocating failed" << endl;

        return MemoryRecord();
    }

void PartitionTable::print() const {
    for (Partition p : _list) {
        p.print();
    }
}

// ===== =====
// ===== =====
// ===== =====

int main() {
    list<Partition> list = {
        {1, 0, 10},
        {2, 10, 18},
        {3, 28, 16},
        {4, 44, 6},
        {5, 50, 21},
        {6, 71, 30}
    };

    PartitionTable t = PartitionTable(list);
    t.print();
    t.allocate("J3", 73);
    t.allocate("J4", 28.2);

    return 0;
}