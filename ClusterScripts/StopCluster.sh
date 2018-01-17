#!/bin/bash
#chmod +x StopCluster.sh
#./StopCluster.sh
startcluster=2300000
endcluster=235000

while (($startcluster <= $endcluster)); do
	qdel $startcluster
	let startcluster=startcluster+1
done
