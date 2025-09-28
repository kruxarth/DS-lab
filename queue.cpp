#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Enqueue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    // Dequeue
    cout << q.front() << " dequeued from queue\n";
    q.pop();

    // Access front and back
    cout << "Front item is " << q.front() << "\n";
    cout << "Rear item is " << q.back() << "\n";

    return 0;
}
