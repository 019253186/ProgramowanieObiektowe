#include <bits/stdc++.h>

#include "../inc/cell.h"

using namespace std;

Type Cell::get_cell_type() {
    return this->cell_type;
}

void Cell::set_text(string t) {
    this->text = t;
}

void Cell::set_number(int n) {
    this->number = n;
}

void Cell::set_type(Type t) {
    this->cell_type = t;
}

int Cell::get_number() {
    return this->number;
}

string Cell::get_text() {
    return this->text;
}