echo $USER >> timing.out
echo `date` >> timing.out
for ((n=0;n<11;n++)); do 
  echo "Iteration $n";
  TEST=`./run.sh`
  echo $TEST
  echo $TEST >> timing.out
done

