#!/bin/bash

for((TAILLE=100;$TAILLE<=10000;TAILLE=TAILLE+100))
	do
	echo ""
	echo "./BIN/optim0.pgr $TAILLE"
	./BIN/optim0.pgr $TAILLE
done

