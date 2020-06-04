#include <bits/stdc++.h>

using namespace std;

enum Type  {
    NUMBER,
    TEXT,
    NONE
};

class Cell{  
    
private:
    Type cell_type = NONE;
    int number;
    string text;

public:
    void set_type(Type t);
    void set_text(string t);
    void set_number(int n);
    Type get_cell_type();
    int get_number();
    string get_text();
};
