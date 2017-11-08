#include <iostream>
#include <string>
using namespace std;

class Reservation {
    private:
        string employee_name;
        string room_number;
    public:
        void set_room(string number) {
            room_number = number;
        };
        void set_name(string name) {
            employee_name = name;
        };
        string get_room() {
            return room_number;
        };
        string get_name() {
            return employee_name;
        };
        void change_room(string new_room) {
            room_number = new_room;
        };
};

class AddressBook {
    private:
        Reservation *elements;
        int size;
    public:
        AddressBook();
        void push_back(Reservation);
        void remove_reservation(int);
        void move_room(int, string);
        void find_employee(int);
        void clear_list();
        void sort_list();

        bool verify_if_exists(string);
        int get_position(string);

        int get_size() {
            return size;
        };
        Reservation get_element(int position) {
            return elements[position];
        };
};

AddressBook::AddressBook() {
    size = 0;
    elements = new Reservation[0];
};

void AddressBook::push_back( Reservation reservation ) {
    Reservation* temp = new Reservation[size+1];
    for ( int i=0 ; i<size ; i++ ) {
        temp[i] = elements[i];
    }
    size++;
    temp[size-1] = reservation;
    delete[] elements;
    elements = temp;
};

void AddressBook::remove_reservation( int position ) {
    Reservation* temp = new Reservation[size-1];
    for ( int i=0 ; i<position ; i++ ) {
        temp[i] = elements[i];
    }
    for ( int i=position ; i<size-1 ; i++ ) {
        temp[i] = elements[i+1];
    }
    size--;
    delete[] elements;
    elements = temp;
}

void AddressBook::move_room( int position, string room ) {
    elements[position].change_room( room );
}

void AddressBook::find_employee( int position ) {
    cout << elements[position].get_name() << " is in room " << elements[position].get_room() << endl;
}

void AddressBook::clear_list() {
    Reservation* temp = new Reservation[0];
    size = 0;
    delete[] elements;
    elements = temp;
}

void AddressBook::sort_list() {
    for( int i=0 ; i < size ; i++ ) {
        for( int j=0 ; j < size-1 ; j++ ) {
            if( elements[j].get_room() > elements[j+1].get_room() ) {
                swap( elements[j], elements[j+1] );
            }
        }
    }
    for ( int i=0 ; i < size ; i++ ) {
        for( int j=0 ; j < size-1 ; j++ ) {
            if( elements[j].get_room() == elements[j+1].get_room() ) {
                if ( elements[j].get_name() > elements[j+1].get_name() ) {
                    swap( elements[j], elements[j+1] );
                }
            }
        }
    }
}

bool AddressBook::verify_if_exists( string name ) {
    for ( int i=0 ; i<size ; i++ ) {
        if ( elements[i].get_name() == name ) {
            return true;
        }
    }
    return false;
};

int AddressBook::get_position( string name ) {
    for ( int i=0 ; i<size ; i++ ) {
        if ( elements[i].get_name() == name ) {
            return i;
        }
    }
}

void case_add(AddressBook* addressbook) {
    string name, room;
    cin >> name >> room;
    Reservation reservation;
    reservation.set_name(name);
    reservation.set_room(room);
    bool does_exist = addressbook->verify_if_exists( name );

    if ( does_exist == true ){
        cerr << "error: entry already exists for this employee" << endl;
    } else {
        addressbook->push_back( reservation );
    }
}

void case_remove(AddressBook* addressbook) {
    string name;
    cin >> name;
    bool does_exist = addressbook->verify_if_exists( name );

    if ( does_exist == true ) {
        int position = addressbook->get_position( name );
        addressbook->remove_reservation( position );
    } else {
        cerr << "error: entry does not exist";
    }
}

void case_move(AddressBook* addressbook) {
    string name, room;
    cin >> name >> room;
    int position = addressbook->get_position( name );
    addressbook->move_room( position, room );
}

void case_find(AddressBook* addressbook) {
    string name;
    cin >> name;
    int position = addressbook->get_position( name );
    addressbook->find_employee( position );
}

void print_list( AddressBook* addressbook ) {
        int list_size = addressbook->get_size();
        for ( int i=0 ; i<list_size ; i++ ) {
            Reservation element = addressbook->get_element(i);
            cout << element.get_name() << " is in room " << element.get_room() << endl;
        }
};

void case_list(AddressBook* addressbook) {
    addressbook->sort_list();
    print_list(addressbook);
}

void case_clear(AddressBook* addressbook) {
    addressbook->clear_list();
}

bool cases( string action, AddressBook* addressbook ) {
    if ( action == "add" ) {
        case_add(addressbook);
        return true;
    }
    else if ( action == "remove" ) {
        case_remove(addressbook);
        return true;
    }
    else if ( action == "move" ) {
        case_move(addressbook);
        return true;
    }
    else if ( action == "find" ) {
        case_find(addressbook);
        return true;
    }
    else if ( action == "list" ) {
        case_list(addressbook);
        return true;
    }
    else if ( action == "clear" ) {
        case_clear(addressbook);
        return true;
    }
    else if ( action == "exit" ) {
        return false;
    }
    else {
        cerr << "error: command " << action << " not recognized" << endl;
    }
}

int main() {
    AddressBook addressbook;
    string action;
    bool loop = true;

    while ( loop == true ) {
        cout << ">";
        cin >> action;
        loop = cases( action, &addressbook );
    }

}
