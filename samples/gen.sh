nbtet=14
mkdir $nbtet
for n in {1..500}
do
	echo "Generation du fichier $n/500";
	python generator.py $nbtet > $nbtet/test$n
done
