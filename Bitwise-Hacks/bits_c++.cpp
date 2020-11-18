// Operations done on individual bits of a number are called bitwise operations.
// Operations:
// - Bitwise AND(&)
// - Bitwise OR(|)
// - Bitwise XOR(^)
// - Bitwise NOT(~)
// Bitwise operations have a time complexity of O(1)

#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define llu unsigned long long

using namespace std;

string to_binary(int x)
{
    string s;
    while(x > 0) {
        s += (x % 2 ? '1' : '0');
        x /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << "Bitwise operations on 2 numbers" << "\n";
    cout << "AND " << to_binary(53 & 20) << "\n";
    cout << "OR " << to_binary(53 | 20) << "\n";
    cout << "XOR " << to_binary(53 ^ 20) << "\n";
    // Bitwise NOT
    cout << "NOT " << ~(53) << "\n";

    // Bitwise Shifts
    // Left shift ( << ):
    // left shift << shifts bits to the left,
    // increasing the value of the number.
    // - An expression x << b is equal to x*(2^b)
    // 13 << 2 = 13 * (2^2) = 13 * 4 = 52
    cout << "Left Shift of 13\n";
    cout << to_binary(13) << " " << (13 << 2) << "\n";

    // Right shift ( >> )
    // - An expression x >> b is equal to floor(x / (2^b))
    // right shift ( >> ) shifts bits to the right
    cout << "Right Shift of 26\n";
    cout << to_binary(26) << " " << to_binary(26 << 1) << "\n";

    // To check if a certain bit is ON in a number
    // If that bit is ON, then it's AND with 1 << i
    // will be 1
    int x = 52;
    cout << "Bits that are ON in 52\n";
    for(int i = 0; i < 30; ++i)
        if(x & (1 << i))
            cout << i << "\n";
    cout << "\n";

    // To turn ON a certain bit in a number
    // We do OR of that number with (1 << i)
    // where i is the bit position number we want to turn on
    int y = 32;
    cout << "Turn ON 5th bit in 32\n";
    cout << to_binary(y) << " " << to_binary(y | (1 << 4)) << "\n";

    // To flip a certain bit in a number, meaning
    // if it's ON, turn it OFF
    // if it's OFF, turn it ON
    // We use XOR, because if the bit is ON, XOR will turn it OFF
    // If it's OFF, it will be ON after XOR with (1 << i)
    // i is the bit position number we want to flip
    int z = 34;
    cout << "Flip 4th bit of 34\n";
    cout << to_binary(z) << " " << to_binary(z ^ (1 << 3)) << "\n";

    return 0;
}
