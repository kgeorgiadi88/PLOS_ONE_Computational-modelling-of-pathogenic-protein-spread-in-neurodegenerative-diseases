#!/bin/bash
#chmod +x CreateFolders.sh
#./CreateFolders.sh
. Parameters.sh
declare -a CurrentExperiment
TotalExperiments=1
i=1
while (($i <= $NumVariables)); do
	let TotalExperiments=TotalExperiments*VariablesSize[i]
	let CurrentExperiment[i]=1
	let i=i+1
done
let CurrentExperiment[NumVariables]=0

experiment=1
while (($experiment <= $TotalExperiments)); do
	echo $experiment
	let j=NumVariables
	let CurrentExperiment[j]=CurrentExperiment[j]+1
	while (($j >= 1)); do
		if ((${CurrentExperiment[$j]} > ${VariablesSize[$j]})); then
			let CurrentExperiment[j]=1
			let CurrentExperiment[j-1]=CurrentExperiment[j-1]+1
		fi
		let j=j-1
	done

	#Create the directories
	for ((j=1;j<=NumVariables;j++)) do
		DIRECTORY="${VariablesNames[$j]}${CurrentExperiment[$j]}"
		if [ ! -d "$DIRECTORY" ]; then
			mkdir "$DIRECTORY"
		fi
		cd $DIRECTORY
	done
	for ((j=1;j<=NumVariables;j++)) do
		cd ..
	done

	let experiment=experiment+1
done
