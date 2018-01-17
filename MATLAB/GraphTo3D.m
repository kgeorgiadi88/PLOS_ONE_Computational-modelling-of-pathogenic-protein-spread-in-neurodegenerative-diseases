function Points3D = GraphTo3D(t, CellTypes, CellColumns, NumTypePerColumn)
NumNeurons = length(CellTypes);

TypeOffsets = zeros(3,40);
TypeOffsets(:,t.E2)   = [0;0;1];
TypeOffsets(:,t.E2B) = [1;0;0.95];
TypeOffsets(:,t.I2)    = [0;1;0.90];
TypeOffsets(:,t.I2L)  = [1;1;0.85];
TypeOffsets(:,t.E4)   = [0;0;0.5];
TypeOffsets(:,t.I4)    = [0;1;0.4];
TypeOffsets(:,t.I4L)  = [1;1;0.35];
TypeOffsets(:,t.E5B) = [1;0;-0.05];
TypeOffsets(:,t.E5R) = [0;0;0];
TypeOffsets(:,t.I5)    = [0;1;-0.1];
TypeOffsets(:,t.I5L)  = [1;1;-0.15];
TypeOffsets(:,t.E6)   = [0;0;-0.5];
TypeOffsets(:,t.I6)    = [0;1;-0.6];
TypeOffsets(:,t.I6L)  = [1;1;-0.65];
ColumnOffset = [2; 1; 0];
AreaSize = 0.3;
Typesteps = zeros(40,1);
Typenum = zeros(40,1);
TypeCounter = zeros(40,max(CellColumns)+1);
for i = 1:length(Typesteps)
    if(NumTypePerColumn(i) > 0)
        Typesteps(i) = AreaSize/(ceil(sqrt(NumTypePerColumn(i)))-1);
        Typenum(i) = ceil(sqrt(NumTypePerColumn(i)));
    end
end

Points3D = zeros(3,NumNeurons);
for neuron = 1:NumNeurons
        type = CellTypes(neuron);
        TypeCounter(type,CellColumns(neuron)+1) = TypeCounter(type,CellColumns(neuron)+1) + 1;
        Points3D(:,neuron) = TypeOffsets(:,type) + CellColumns(neuron)*ColumnOffset + [mod(TypeCounter(type,CellColumns(neuron)+1)-1,Typenum(type))*Typesteps(type);floor((TypeCounter(type,CellColumns(neuron)+1)-1)/Typenum(type))*Typesteps(type);0];
end

end

