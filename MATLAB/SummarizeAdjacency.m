function SummaryAdjacency = SummarizeAdjacency(Adjacency, CellTypes, CellColumns, TotalPoints)
NumNeurons = size(Adjacency,1);
NumColumns = max(CellColumns)+1;
SummaryAdjacency = zeros(40*NumColumns);
for i = 1:NumNeurons
    for j = 1:NumNeurons
        from = CellTypes(i);
        to = CellTypes(j);
        fromcol = CellColumns(i)+1;
        tocol = CellColumns(j)+1;
        SummaryAdjacency(from+(fromcol-1)*40,to+(tocol-1)*40) = SummaryAdjacency(from+(fromcol-1)*40,to+(tocol-1)*40) + Adjacency(i,j);
    end
end
for i = 1:NumColumns*40
    for j = 1:NumColumns*40
        if(TotalPoints(i) > 0  && TotalPoints(j))
              SummaryAdjacency(i,j) = SummaryAdjacency(i,j)/(TotalPoints(i)*TotalPoints(j));
        end
    end
end
end