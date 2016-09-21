#include "hello-world.h"

int main (int argc, char* argv[]) {
  while (true) {
    led0 = !button;
    led1 = button;
    led2 = !button;
  }
}
