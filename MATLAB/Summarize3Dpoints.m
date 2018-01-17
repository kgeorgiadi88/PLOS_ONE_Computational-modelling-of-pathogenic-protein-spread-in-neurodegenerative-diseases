function [SummaryPoints3D, SummaryPointsColumns, TotalPoints] = Summarize3Dpoints(Points3D, CellTypes, CellColumns)
NumNeurons = length(CellTypes);
NumColumns = max(CellColumns)+1;
SummaryPoints3D = zeros(3,40*NumColumns);
SummaryPointsColumns = zeros(1,40*NumColumns);
TotalPoints = zeros(1,40*NumColumns);
for neuron = 1:NumNeurons
        type = CellTypes(neuron);
        column = CellColumns(neuron);
        SummaryPoints3D(:,type+column*40) = SummaryPoints3D(:,type+column*40) + Points3D(:,neuron);
        TotalPoints(type+column*40) = TotalPoints(type+column*40) + 1;
        SummaryPointsColumns(type+column*40) = column+1;
end
for type = 1:40
    for column = 0:NumColumns-1
        if(TotalPoints(type+column*40)>0)
            SummaryPoints3D(:,type+column*40) = SummaryPoints3D(:,type+column*40)/TotalPoints(1,type+column*40);
        end
    end
end
end