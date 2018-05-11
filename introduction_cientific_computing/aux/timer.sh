#!/bin/bash





MEAN_TIMES=10
INCR=1

rm -f mean_time.txt
for (( i=1;$i<=$#;i=$i+1 ))
do
   echo ${!i}  #imprime a discretizacao sendo executada
   rm -f Resultados/${!i}.txt
   let pi=$INCR
   while [ $pi -le $MEAN_TIMES ]
   do
      likwid-pin -q -c N:3 ./pdeSolver -nx ${!i} -ny ${!i} -o ${!i}.txt -m gs -i 10
      let pi=$pi+$INCR
   done
done


