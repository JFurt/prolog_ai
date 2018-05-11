#!/bin/bash





MEAN_TIMES=1
INCR=1

rm -f mean_time.txt
for (( i=1;$i<=$#;i=$i+1 ))
do
   echo ${!i}  #imprime a discretizacao sendo executada
   rm -f Resultados/${!i}.txt
   let pi=$INCR
   while [ $pi -le $MEAN_TIMES ]
   do
      likwid-perfctr -m -C 3 -g FLOPS_DP -o ${!i}FLOPSDP.txt ./pdeSolver -nx ${!i} -ny ${!i} -o ${!i}_FLOPS.txt -m gs -i 10
      #likwid-perfctr -C 3 -g CACHES -o ${!i}CACHE.txt ./pdeSolver -nx ${!i} -ny ${!i} -o ${!i}_CACHE.txt -m gs -i 10
      likwid-perfctr -m -C 3 -g MEM -o ${!i}MEM.txt ./pdeSolver -nx ${!i} -ny ${!i} -o ${!i}_MEM.txt -m gs -i 10
      let pi=$pi+$INCR
   done
done


