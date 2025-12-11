#include <iostream>
#include <string>
using namespace std;

string toBinary8(int n) {
    string b = "";
    for (int i = 7; i >= 0; i--) {
        int bit = (n >> i) & 1;
        b += char(bit + '0');
        if (i == 4) b += ' ';
    }
    return b;
}

string toHex2(int n) {
    string h = "";
    for (int i = 1; i >= 0; i--) {
        int digit = (n >> (4*i)) & 0xF;
        if (digit < 10) h += char('0' + digit);
        else            h += char('A' + (digit - 10));
    }
    return h;
}

string digitToBCD(int d) {
    string b = "";
    for (int i = 3; i >= 0; i--) {
        int bit = (d >> i) & 1;
        b += char(bit + '0');
    }
    return b;
}

string toBCD(int n) {
    int hundreds = n / 100;         // 0–2
    int tens     = (n / 10) % 10;   // 0–9
    int ones     = n % 10;          // 0–9

    string bcd = digitToBCD(hundreds) + " " +
                 digitToBCD(tens)     + " " +
                 digitToBCD(ones);

    return bcd;
}

int main() {
    cout << "DECIMAL                               BINARY                                      HEXADECIMAL                                            BCD\n";

    for (int i = 0; i < 256; i++) {
        string dec = to_string(i);

        cout << dec;
        for (int s = dec.length(); s < 40; s++) cout << " ";

        cout << toBinary8(i);
        for (int s = 0; s < 42; s++) cout << " ";

        cout << toHex2(i);
        for (int s = 0; s < 45; s++) cout << " ";

        cout << toBCD(i) << "\n";
    }

    return 0;
}
