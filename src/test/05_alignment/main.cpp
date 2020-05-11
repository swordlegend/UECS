#include <UECS/World.h>

#include <iostream>

using namespace Ubpa;
using namespace std;

struct alignas(1) A {
	A() { cout << "A: " << this << endl; }
	char pad[13];
};
struct alignas(4) B {
	B() { cout << "B: " << this << endl; }
	char pad[28];
};
struct alignas(1) C {
	C() { cout << "C: " << this << endl; }
	char pad[15];
};
struct alignas(2) D {
	D() { cout << "D: " << this << endl; }
	char pad[10];
};
struct alignas(8) E {
	E() { cout << "E: " << this << endl; }
	char pad[24];
};

int main() {
	CmptRegistrar::Instance().Register<A, B, C, D, E>();
	World w;
	w.entityMngr.CreateEntity<A, B, C, D, E>();
	return 0;
}
