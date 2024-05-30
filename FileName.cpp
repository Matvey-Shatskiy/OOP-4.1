#include <iostream>
#include <string>
#include <set>

using namespace std;

class Word {
public:
    Word() {
        data = "";
    }

    Word(const string& str) {
        data = str;
    }

    Word(char ch, int count) {
        data = string(count, ch);
    }

    Word(const string& str, int n, bool from_start) {
        if (from_start) {
            data = str.substr(0, n);
        }
        else {
            data = str.substr(str.size() - n, n);
        }
    }

    Word(const Word& other) {
        data = other.data;
    }

    Word(Word&& other) {
        data = move(other.data);
    }

    void fillFromKeyboard() {
        cout << "Введите слово: ";
        cin >> data;
    }

    void print() {
        cout << "Слово: " << data << endl;
    }

    void findAndPrintRepeatedLetters() const {
        set<char> found;
        set<char> printed;
        for (size_t i = 0; i < data.size(); ++i) {
            if (found.find(data[i]) != found.end() && printed.find(data[i]) == printed.end()) {
                cout << data[i] << " ";
                printed.insert(data[i]);
            }
            found.insert(data[i]);
        }
        cout << endl;
    }

private:
    string data;
};

int main() {
    setlocale(LC_ALL, "RU");
    Word word1;
    word1.fillFromKeyboard();
    word1.print();

    Word word2("Mamamama");
    word2.print();

    Word word3('a', 5);
    word3.print();

    Word word4("abcdefgh", 5, true);
    word4.print();

    Word word5("abcdefgh", 5, false);
    word5.print();

    Word word6(word2);
    word6.print();

    Word word7(move(word3));
    word7.print();

    word2.findAndPrintRepeatedLetters();

    return 0;
}
