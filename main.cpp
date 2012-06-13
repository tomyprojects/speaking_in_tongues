#include <iostream>
#include <vector>
#include <numeric>
#include <memory>
#include <deque>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

class char_type;

typedef map<char, char_type> googlerese_map;

void read_file(const char * name, vector<string> & test_cases)
{
    fstream f(name, ios::in);

    if (!f.is_open())
        throw "Error";

    string line;

    std::getline(f, line);
    std::stringstream  linestream(line);

    int  value;
    linestream >> value;

    while (value--)
    {
        getline(f,line);
        test_cases.push_back(line);
    }

    f.close();
}

void print_string(string & s) { cout << s << endl; }

class print_string_2
{
    int i;
public:
    print_string_2() : i(0) {}
    void operator() (string const& s) { cout << "Case #" << ++i << ": " << s << endl; }
};

class char_type
{
    char data;
public:
    char_type() : data('?') {}
    char_type(char c) : data(c) {}
    operator char& () { return data; }
};

class decode_string
{
    googlerese_map & mdecoder;
public:
    decode_string(googlerese_map & decoder) : mdecoder(decoder) {}
    void operator() (string & s)
    {
        for (int i=0; i<s.size(); i++)
        {
            s[i] = (char) mdecoder[s[i]];
        }
    }
};

void add_mapping(string const& key, string const& s, googlerese_map & m)
{
    for (int i=0; i<key.size(); i++)
    {
        if (m.insert(make_pair(key[i],s[i])).second == false)
        {
            if (m[key[i]] != s[i])
            {
                cout << "\n\tError! " << key[i] <<  m[key[i]] << s[i] << "\n" << endl;
            }
        }
    }
}

void insert_samples(googlerese_map & googlerese)
{
    googlerese.insert(make_pair('y','a'));

    googlerese.insert(make_pair('e','o'));

    googlerese.insert(make_pair('q','z'));

    googlerese.insert(make_pair('z','q'));

    add_mapping("ejp mysljylc kd kxveddknmc re jsicpdrysi",
                "our language is impossible to understand",
                googlerese);

    add_mapping("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                "there are twenty six factorial possibilities",
                googlerese);

    add_mapping("de kr kd eoya kw aej tysr re ujdr lkgc jv",
                "so it is okay if you want to just give up",
                googlerese);
}

void write_to_file(const char * name, vector<string> & v)
{
    fstream f(name, ios::out);

    if (!f.is_open())
        throw "Error";

    for (int i=0; i<v.size(); i++)
        f << "Case #" << i+1 << ": " << v[i] << endl;

    f.close();
}

int main(int argc, char *argv[])
{
    vector<string> test_cases;

    read_file("/Users/tyeung/Google Drive/Qt/consoleapp/A-small-practice.in", test_cases);

    for_each(test_cases.begin(), test_cases.end(), print_string_2());

    googlerese_map googlerese;

    insert_samples(googlerese);

    cout << "---------------\n";

    for_each(test_cases.begin(), test_cases.end(), decode_string(googlerese));

    for_each(test_cases.begin(), test_cases.end(), print_string_2());

    write_to_file("/Users/tyeung/Google Drive/Qt/consoleapp/A-small-practice.txt", test_cases);

    return 0;
}
