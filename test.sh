nbtet=$1
mkdir -p results/mine_$nbtet
for n in {1..500}
do
	echo "Processing file $n of 500"
	./fillit samples/$nbtet/test$n > results/mine_$nbtet/test$n
done
