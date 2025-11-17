#include <iostream>
#include <fstream>
#include <unistd.h>

void writeToFile(const std::string &path, int value) {
    std::ofstream file(path);
    if (!file) {
        std::cerr << "Cannot open " << path << std::endl;
        return;
    }
    file << value;
    file.close();
}

int main() {
    std::string pwmEnable = "/sys/class/hwmon/hwmon3/pwm1_enable";
    std::string pwmValue  = "/sys/class/hwmon/hwmon3/pwm1";

    // เปิดโหมด MANUAL
    writeToFile(pwmEnable, 1);

    int speed;
    std::cout << "Enter fan speed (0-255): ";
    std::cin >> speed;

    if (speed < 0 || speed > 255) {
        std::cerr << "Invalid value!" << std::endl;
        return 1;
    }

    writeToFile(pwmValue, speed);
    std::cout << "Fan speed set to " << speed << std::endl;

    return 0;
}
