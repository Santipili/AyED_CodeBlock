#include <string>
#include <ctime>
#include <iostream>
using namespace std;

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
// si quisiera usar put_time() deberia poner la libreria <iomanip>

const string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

int main() {
    cout << "currentDateTime()=" << currentDateTime() << endl;
    getchar();  // wait for keyboard input
}
