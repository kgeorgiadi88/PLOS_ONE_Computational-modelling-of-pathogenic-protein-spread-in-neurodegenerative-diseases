#!/bin/bash
#chmod +x ProcessResults.sh
#./ProcessResults.sh
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
STARTINGDIR=$PWD
experiment=1
while (($experiment <= $TotalExperiments)); do
	let j=NumVariables
	let CurrentExperiment[j]=CurrentExperiment[j]+1
	while (($j >= 1)); do
		if ((${CurrentExperiment[$j]} > ${VariablesSize[$j]})); then
			let CurrentExperiment[j]=1
			let CurrentExperiment[j-1]=CurrentExperiment[j-1]+1
		fi
		let j=j-1
	done

	for ((j=1;j<=NumVariables;j++)) do
		DIRECTORY="${VariablesNames[$j]}${CurrentExperiment[$j]}"
		if [ -d "$DIRECTORY" ]; then
			cd $DIRECTORY
			CURRENTDIR=$PWD
		fi
	done
	qsub -l h_rt=00:10:00 -l tmem=8.0G -l h_vmem=8.0G -l s_stack=10240 -j y -b y -cwd -V matlab -nodesktop -nodisplay -nosplash -nojvm -r letsprocesscluster
	for ((j=1;j<=NumVariables;j++)) do
		cd ..
	done

	let experiment=experiment+1
done
