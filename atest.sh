#!/bin/bash
cd $HOME/inf304
echo [test 0]
echo cas correcte
./curiosity-test ./test_tp7/test_C_erreur0.test | tail -n 3
echo
echo cas incorrecte
./curiosity-test0 ./test_tp7/test_C_erreur0.test | tail -n 5 | sed /'#'/d
echo

echo [test 2]
echo cas correcte
./curiosity-test ./test_tp7/test_X_erreur2.test | tail -n 3
echo
echo cas incorrecte
./curiosity-test2 ./test_tp7/test_X_erreur2.test | tail -n 5 | sed /'#'/d
echo

echo [test 3]
echo cas correcte
./curiosity-test ./test_tp7/test_M_erreur3.test  | tail -n 3
echo
echo cas incorrecte
./curiosity-test3 ./test_tp7/test_M_erreur3.test | tail -n 5 | sed /'#'/d
echo

echo [test 4]
echo cas correcte
./curiosity-test ./test_tp7/test_M_erreur4.test | tail -n 3
echo
echo cas incorrecte
./curiosity-test4 ./test_tp7/test_M_erreur4.test | tail -n 5 | sed /'#'/d
echo

echo [test 5]
echo cas correcte
./curiosity-test ./test_tp7/test_erreur5.test | tail -n 3
echo
echo cas incorrecte
./curiosity-test5 ./test_tp7/test_erreur5.test | tail -n 5 | sed /'#'/d
echo

echo [test 6]
echo cas correcte
./curiosity-test ./test_tp7/test_erreur6_obstacle.test | tail -n 3
echo
echo cas incorrecte
./curiosity-test6 ./test_tp7/test_erreur6_obstacle.test | tail -n 5 | sed /'#'/d
echo

echo [test 8]
echo cas correcte
./curiosity-test ./test_tp7/test_B_erreur8.test | tail -n 3
echo
echo cas incorrecte
./curiosity-test8 ./test_tp7/test_B_erreur8.test | tail -n 5 | sed /'#'/d
echo

echo [test 9]
echo cas correcte
./curiosity-test ./test_tp7/test_op_erreur9.test | tail -n 3
echo
echo cas incorrecte
./curiosity-test9 ./test_tp7/test_op_erreur9.test | tail -n 5 | sed /'#'/d