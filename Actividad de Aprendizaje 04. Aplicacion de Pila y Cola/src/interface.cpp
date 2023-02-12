// interface.cpp
#include "interface.hpp"

using namespace std;
Interface::Interface() {}
int Interface::toInt(const char& myChar) {
  switch (myChar) {
    case '+':
      return 1;
    case '-':
      return 1;
    case '*':
      return 2;
    case '/':
      return 2;
    case '^':
      return 3;
    case '(':
      return 4;
    case ')':
      return 5;
    default:
      return 0;
  }
}
void Interface::getString() {
  string temporal;
  getline(cin, temporal);
  for (int i = 0; i < temporal.size(); i++) {
    input.enqueue(temporal[i]);
  }
}
void Interface::infixToPostfix() {
  while (!input.isEmpty()) {
    switch (toInt(input.getFront())) {
      case 0:
        output.enqueue(input.getFront());
        input.dequeue();
        break;
      case 1:
      case 2:
      case 3:
        if (temporal.isEmpty()) {
          temporal.push(input.getFront());
          input.dequeue();
        } else {
          if (toInt(temporal.getTop()) >= toInt(input.getFront()) &&
              toInt(temporal.getTop()) != 4) {
            while (!temporal.isEmpty() && toInt(temporal.getTop()) != 4) {
              if (toInt(temporal.getTop()) < toInt(input.getFront())) {
                break;
              }
              output.enqueue(temporal.getTop());
              temporal.pop();
            }
            temporal.push(input.getFront());
            input.dequeue();
          } else {
            temporal.push(input.getFront());
            input.dequeue();
          }
        }
        break;
      case 4:
        temporal.push(input.getFront());
        input.dequeue();
        break;
      case 5:
        input.dequeue();
        while (toInt(temporal.getTop()) != 4) {
          output.enqueue(temporal.getTop());
          temporal.pop();
        }
        temporal.pop();
        break;
      default:
        cout << "SOMETHING WENT WRONG";
        system("pause");
        break;
    }
  }
  while (!temporal.isEmpty()) {
    output.enqueue(temporal.getTop());
    temporal.pop();
  }
}

void Interface::printsOutput() {
  while (!output.isEmpty()) {
    cout << output.getFront();
    output.dequeue();
  }
  cout << endl;
}

void Interface::execute() {
  bool flag = true;
  while (flag) {
    char option;
    cin.ignore();
    cout << "Introduce la cadena a convertir: " << endl;
    getString();
    cout << "Cadena convertida: " << endl;
    infixToPostfix();
    printsOutput();
    output.removesAll();
    cout << "Desea ingresar otra cadena[s/n]: " << endl;
    cin >> option;
    switch (option) {
      case 's':
        execute();
        break;
      case 'n':
        flag = exit();
        break;
      default:
        cout << "Ingrese una opcion correcta" << endl;
        break;
    }
  }
}

bool Interface::exit() { return false; }