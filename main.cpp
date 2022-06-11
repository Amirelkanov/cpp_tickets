#include <string>
#include <memory>
#include <iostream>

using namespace std;
class Person {
public:
    Person(std::string name_, shared_ptr<Person> colleague = nullptr) : name_(std::move(name_)), colleague_(colleague) {};

    Person() : Person("", 0) {};

    void set_colleague(shared_ptr<Person> new_colleague) {
        colleague_ = new_colleague;
    }

    void print_name() {std::cout << name_;}
private:
    std::string name_;
    shared_ptr<Person> colleague_;
};

int main() {
    shared_ptr<Person> first_person(new Person("Alice"));
    shared_ptr<Person> second_person(new Person("Bob"));
    first_person->set_colleague(second_person);
    second_person->set_colleague(first_person);

}