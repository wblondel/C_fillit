for nbtet in {1..26}
do
	mkdir $nbtet
	for n in {1..500}
	do
		echo "Generation du fichier $n/500";
		python3 generator.py $nbtet > $nbtet/test$n
	done
done
