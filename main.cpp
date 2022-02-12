#include <iostream>
#include "lvector.h"

using namespace std;

class Controller {
public:
    Controller() { cout << "Create" << endl; }
    Controller(const Controller&) { cout << "Copy create" << endl; }
    Controller(Controller&&) { cout << "Move create" << endl; }
    void operator=(const Controller&) { cout << "Copy" << endl; }
    void operator=(Controller&&) { cout << "Move" << endl; }
};

int main()
{
    LVector<Controller> vec;
    Controller ctrl;

    //vec.append(ctrl);
    vec.append(std::move(ctrl));
    vec.append(std::move(ctrl));
    vec.append(std::move(ctrl));
    return 0;
}
