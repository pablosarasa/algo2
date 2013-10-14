#include <iostream>
#include "ConjuntoABB.hpp"
#include "mini_test.h"


void check_crear_conjunto() {

  Conjunto<int> c;
  ASSERT_EQ(c.pertenece(1), false);
  ASSERT_EQ(c.pertenece(2), false);


  c.insertar(1);
  ASSERT_EQ(c.pertenece(1), true);
  ASSERT_EQ(c.pertenece(2), false);

}

void check_insertar_conjunto() {

  Conjunto<int> c;
  ASSERT_EQ(c.pertenece(1), false);
  ASSERT_EQ(c.pertenece(2), false);


  c.insertar(1);
  ASSERT_EQ(c.pertenece(1), true);
  ASSERT_EQ(c.pertenece(2), false);

  c.insertar(2);
  ASSERT_EQ(c.pertenece(0), false);
  ASSERT_EQ(c.pertenece(1), true);
  ASSERT_EQ(c.pertenece(2), true);

  c.insertar(4);
  c.insertar(3);
  c.insertar(5);
  ASSERT_EQ(c.pertenece(0), false);
  ASSERT_EQ(c.pertenece(1), true);
  ASSERT_EQ(c.pertenece(2), true);
  ASSERT_EQ(c.pertenece(3), true);
  ASSERT_EQ(c.pertenece(4), true);

}

void check_remover_conjunto() {

  Conjunto<int> c;

  c.insertar(2);
  c.insertar(5);
  c.remover(2);
  ASSERT_EQ(c.pertenece(2), false);
  ASSERT_EQ(c.pertenece(5), true);

  c.remover(2);
  c.remover(5);

  ASSERT_EQ(c.pertenece(2), false);
  ASSERT_EQ(c.pertenece(5), false);

  c.insertar(1);
  c.insertar(2);
  c.insertar(3);
  c.insertar(4);
  c.remover(4);
  ASSERT_EQ(c.pertenece(1), true);
  ASSERT_EQ(c.pertenece(2), true);
  ASSERT_EQ(c.pertenece(3), true);
  ASSERT_EQ(c.pertenece(4), false);
  ASSERT_EQ(c.minimo(),1);
  ASSERT_EQ(c.maximo(),3);
 }


int main() {
  RUN_TEST(check_crear_conjunto);
  RUN_TEST(check_insertar_conjunto);
  RUN_TEST(check_remover_conjunto);

  return 0;
}
