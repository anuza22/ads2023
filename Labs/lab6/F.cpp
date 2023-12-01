#include <iostream>
#include <map>
#include <iomanip>
#include <vector>

using namespace std;

struct Student {
    double gpa;
    string first_name;
    string last_name;

    Student(double gpa, string first, string last) {
        this->gpa = gpa;
        this->first_name = first;
        this->last_name = last;
    }

    bool comesBefore(string a, string b) {
        int size = min(a.size(), b.size());
        
        for (int i = 0; i < size; i++) {
            if (a[i] < b[i]) return true;
            else if (a[i] > b[i]) return false;
        }
        return size == a.size();
    }

    bool isLessThan(Student other) {
        if (this->gpa < other.gpa) return true;
        else if (this->gpa == other.gpa) {
            if (this->first_name == other.first_name) {
                return comesBefore(this->last_name, other.last_name);
            }
            else {
                return comesBefore(this->first_name, other.first_name);
            }
        }
        return false;
    }
};

struct Heap {
    vector<Student> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (i * 2) + 1; }
    int right(int i) { return (i * 2) + 2; }

    void insert(Student val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i != 0 && heap[i].isLessThan(heap[parent(i)])) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    Student extractMin() {
        if (heap.size() == 0) return Student(0, "", "");
        if (heap.size() == 1) {
            Student min = heap[0];
            heap.pop_back();
            return min;
        }
        Student min = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return min;
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap.size() && heap[l].isLessThan(heap[smallest])) smallest = l;
        if (r < heap.size() && heap[r].isLessThan(heap[smallest])) smallest = r;
        if (smallest != i) {
            swap(heap[smallest], heap[i]);
            heapify(smallest);
        }
    }

    void print() {
        while (heap.size() != 0) {
            Student student = extractMin();
            cout << student.first_name << " " << student.last_name << " " << fixed << setprecision(3) << student.gpa << '\n';
        }
    }
};

int main() {
    int n;
    cin >> n;
    map<string, double> marks;
    marks["F"] = 0.0;
    marks["D"] = 1.0;
    marks["D+"] = 1.5;
    marks["C"] = 2.0;
    marks["C+"] = 2.5;
    marks["B"] = 3.0;
    marks["B+"] = 3.5;
    marks["A"] = 3.75;
    marks["A+"] = 4.0;

    vector<Student> students;

    Heap heap;

    for (int i = 0; i < n; i++) {
        string first_name, last_name;
        cin >> first_name >> last_name;
        int num;
        cin >> num;
        int total_credits = 0;
        double total_score = 0;

        for (int j = 0; j < num; j++) {
            string mark;
            int credits;
            cin >> mark >> credits;
            total_score += marks[mark] * credits;
            total_credits += credits;
        }

        double gpa = total_score / total_credits;
        Student student = Student(gpa, first_name, last_name);
        students.push_back(student);
        heap.insert(student);
    }
    heap.print();
}
