#include <iostream>
#include <string>
using namespace std;

struct User {
  unsigned id;
  char name[32];
  short age;
};

struct Message {
  int id;
  char content[1024];
  User from, to;
};


void set_user(User& u, int id, const char* name, short age) {
  u.id = id;
  u.age = age;
  strncpy(u.name, name, 25);
}

User new_user(int id, const char* name, short age) {
  User u;
  set_user(u, id, name, age);

  return u;
}

void print_user(const User& u) {
  cout << u.id << " " << u.name << " " << u.age << endl;
}

Message send_message(int id, const char* msg, const User& from, const User& to) {
  Message m;

  m.id = id;
  strncpy(m.content, msg, 1024);
  m.from = from;
  m.to = to;

  return m;
}

void print_message(const Message& msg) {
  cout << "Message ID: " << msg.id << endl;
  cout << "From: ";
  print_user(msg.from);
  cout << "To: ";
  print_user(msg.to);

  cout << "Content: " << msg.content << endl;
}


int main() {

  // User u;
  // u.id = 1;
  // u.age = 32;
  // strcpy(u.name, "Bobi");

  // User a, b;
  // set_user(a, 1, "Vasko", 19);
  // set_user(b, 1, "Vasko", 19);

  User a = new_user(1, "Vaskooo", 19);
  User b = new_user(2, "Pepi", 21);

  print_user(a);
  print_user(b);

  Message msg = send_message(32, "Hello, it's me!", a, b);

  cout << "~~~~~~~~~~~" << endl;

  print_message(msg);

  return 0;
}
