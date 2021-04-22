#include <iostream>
#include <string>
#include <list>

using namespace std;


// ===== =====

class Process {
private:
	string _name;
	int _arrival_time, _served_time, _priority;
	// _time_tarting = -1 by default, means haven't start yet.
	int _time_remaining, _time_starting;

public:
	Process(string name,
		int arrival_time, int served_time, int priority);

	~Process();

	// Return true if the process is end.
	bool isEnd();

	// Schedule this process.
	// Return -1 if schedule is not succeed (already end).
	// Return the actual schedule time if succeed.
	// e.g.
	// _time_remaining = 1
	// schedule(3);
	// will return 1;
	int schedule(int schedule_time);

	int getArrivalTime() const;
	int getPriority() const;
	int getStartTime() const;
	int getServedTime() const;

	void setStartTime(int start_time);

	void print() const;
};

Process::Process(string name,
	int arrival_time, int served_time, int priority) :
	_name(name),
	_arrival_time(arrival_time),
	_served_time(served_time),
	_priority(priority) {
		_time_remaining = _served_time;
		_time_starting = -1;
	}

Process::~Process() {}

bool Process::isEnd() {
	if (_time_remaining) return false;
	return true;
}

int Process::schedule(int schedule_time) {
	if (isEnd()) return -1;

	if (schedule_time <= _time_remaining) {
		_time_remaining -= schedule_time;
		return schedule_time;
	}
	else {
		int tmp = _time_remaining;
		_time_remaining = 0;
		return tmp;
	}
}

int Process::getArrivalTime() const {
	return _arrival_time;
}

int Process::getPriority() const {
	return _priority;
}

int Process::getStartTime() const {
	return _time_starting;
}

int Process::getServedTime() const {
	return _served_time;
}

void Process::setStartTime(int start_time) {
	_time_starting = start_time;
}

void Process::print() const {
	cout << "Process name: " << _name
		<< "\tarrival time: " << _arrival_time
		<< "\tserved time: " << _served_time
		<< "\tstarting time: " << _time_starting;
}



// ===== =====

class Processor {
private:
	// start from 0.
	int _current_time;
	// sor by arrival time.
	list<Process> _coming_list;
	list<Process> _processing_list;

public:
	Processor();
	~Processor();

	// Return true if all lists are empty.
	bool isEmpty();

	void push(Process process);

	// Run the processor;
	void run();
};

Processor::Processor() : _current_time(0) {}
Processor::~Processor() {}


bool Processor::isEmpty() {
	if (_coming_list.empty() &&
		_processing_list.empty()) return true;

	return false;
}

void Processor::push(Process process) {
	_coming_list.push_back(process);

	_coming_list.sort([](Process p1, Process p2) {
		return p1.getArrivalTime() < p2.getArrivalTime();
	});
}

void Processor::run() {
	while (!isEmpty()) {
		if (_current_time == _coming_list.front().getArrivalTime()) {
			Process p = _coming_list.front();
			p.setStartTime(_current_time);

			_processing_list.push_back(p);
			_processing_list.sort([](Process p1, Process p2) {
				return p1.getPriority() > p2.getPriority();
			});
			_coming_list.erase(_coming_list.begin());
		}

		int time = 1;
		if (!_processing_list.empty()) {

			Process p = _processing_list.front();
			_processing_list.erase(_processing_list.begin());

			time = p.schedule(1);
			// haven't end
			if (time != -1) {
				_processing_list.push_back(p);
				_processing_list.sort([](Process p1, Process p2) {
					return p1.getPriority() > p2.getPriority();
				});
			}
			else {
				p.print();
				int t = p.getStartTime();
				int turnaround_time = _current_time - t;
				double powered_turnaround_time = turnaround_time / p.getServedTime();

				cout << "\tfinishing time: " << _current_time
					<< "\tturnaround time: " << turnaround_time
					<< "\tpowered turnaround time: " << powered_turnaround_time
					<< endl;
			}
		}
		_current_time += time;
	}
}


// ===== =====
// ===== =====
// ===== =====

int main() {
	Processor p;
	p.push({"A", 0, 5, 12});
	p.push({"B", 1, 3, 31});
	p.push({"C", 2, 2, 21});
	p.push({"D", 3, 1, 10});

	p.run();
	return 0;
}