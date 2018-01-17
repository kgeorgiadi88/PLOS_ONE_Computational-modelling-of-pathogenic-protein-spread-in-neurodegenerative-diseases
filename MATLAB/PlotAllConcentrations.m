function PlotAllConcentrations( CurrentLoadDirectory, CurrentSaveDirectory, savepdf)
AllConcentrationsMisfolded = dlmread([CurrentLoadDirectory 'AllConcentrationsMisfolded.dat']);
AllConcentrationsNormal = dlmread([CurrentLoadDirectory 'AllConcentrationsNormal.dat']);
CellColumns = dlmread([CurrentLoadDirectory 'SaveCellColumns.dat']);
CellTypes = dlmread([CurrentLoadDirectory 'SaveCellTypes.dat']);
VideoColors = dlmread('VideoColors.dat');
VideoColors = double(uint8(2*VideoColors))/256;
%CellColumns(1) up to CellColumns(180) are the same cell type... likewise
%for every pair: 181-255, 256-294, etc.
ChangeCellTypes = [1 180 181 255 256 294 295 345 346 540 541 615 616 654 655 744 745 804 805 846 847 1272 1273 1296 1297 1371 1372 1410];


MisfoldedDend = AllConcentrationsMisfolded(1:3:end,:);
MisfoldedSoma = AllConcentrationsMisfolded(2:3:end,:);
MisfoldedAxon = AllConcentrationsMisfolded(3:3:end,:);
NormalDend = AllConcentrationsNormal(1:3:end,:);
NormalSoma = AllConcentrationsNormal(2:3:end,:);
NormalAxon = AllConcentrationsNormal(3:3:end,:);
for i = size(MisfoldedDend,2):-1:1
    if(nnz(MisfoldedDend(:,i)) > 0)
        stopat = i;
        break;
    end
end

MisfoldedDend = MisfoldedDend(:,1:stopat);
MisfoldedSoma = MisfoldedSoma(:,1:stopat);
MisfoldedAxon = MisfoldedAxon(:,1:stopat);
NormalDend = NormalDend(:,1:stopat);
NormalSoma = NormalSoma(:,1:stopat);
NormalAxon = NormalAxon(:,1:stopat);



%fig 4
FontSizeAll = 8;
width = 30;
height = 20;
h4 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],...
    'PaperUnits','centimeters',...
    'PaperSize',[width height],...
    'PaperPositionMode','auto',...
    'InvertHardcopy', 'on',...
    'Renderer','opengl'...
    );

for j = 1:6
    subplot(2,3,j);
    if(j==1)
        imagesc(linspace(0,10*size(NormalDend,2), size(NormalDend,2)), 1:size(NormalDend,1), NormalDend); 
    elseif(j==2)
        imagesc(linspace(0,10*size(NormalDend,2), size(NormalDend,2)), 1:size(NormalDend,1), NormalSoma);     
    elseif(j==3)
        imagesc(linspace(0,10*size(NormalDend,2), size(NormalDend,2)), 1:size(NormalDend,1), NormalAxon);
    elseif(j==4)
        imagesc(linspace(0,10*size(NormalDend,2), size(NormalDend,2)), 1:size(NormalDend,1), MisfoldedDend);
    elseif(j==5)
        imagesc(linspace(0,10*size(NormalDend,2), size(NormalDend,2)), 1:size(NormalDend,1), MisfoldedSoma);
    elseif(j==6)
        imagesc(linspace(0,10*size(NormalDend,2), size(NormalDend,2)), 1:size(NormalDend,1), MisfoldedAxon);
    end

colorbar; colormap hot; xlabel('Time','FontSize',FontSizeAll);	set(gcf, 'Color', 'w');set(gca,'FontSize',FontSizeAll);set(gcf, 'Color', 'w');set(gca,'ycolor',[1 1 1 ]); set(gca,'ytick',[]);colorbar;

for i = ChangeCellTypes; line(xlim+[-10 0],[1 1]*i + 0.5,'color','white','LineWidth',0.1,'Clipping','off');  end
i=1;tE6   = text(-0.25*10*size(NormalDend,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'E6RS','FontSize',FontSizeAll);
i=2;tI6   = text(-0.25*10*size(NormalDend,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'I6FS','FontSize',FontSizeAll);
i=3;tI6L  = text(-0.25*10*size(NormalDend,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'I6LTS','FontSize',FontSizeAll);
i=4;tE5B  = text(-0.25*10*size(NormalDend,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'E5IB','FontSize',FontSizeAll);
i=5;tE5R  = text(-0.25*10*size(NormalDend,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'E5RS','FontSize',FontSizeAll);
i=6;tI5   = text(-0.25*10*size(NormalDend,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'I5FS','FontSize',FontSizeAll);
i=7;tI5L  = text(-0.25*10*size(NormalDend,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'I5LTS','FontSize',FontSizeAll);
i=8;tE4   = text(-0.25*10*size(NormalDend,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'E4RS','FontSize',FontSizeAll);
i=9;tI4   = text(-0.25*10*size(NormalDend,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'I4FS','FontSize',FontSizeAll);
i=10;tI4L = text(-0.25*10*size(NormalDend,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'I4LTS','FontSize',FontSizeAll);
i=11;tE2  = text(-0.25*10*size(NormalDend,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'E2RS','FontSize',FontSizeAll);
i=12;tE2B = text(-0.25*10*size(NormalDend,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'E2IB','FontSize',FontSizeAll);
i=13;tI2  = text(-0.25*10*size(NormalDend,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'I2FS','FontSize',FontSizeAll);
i=14;tI2L = text(-0.25*10*size(NormalDend,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'I2LTS','FontSize',FontSizeAll);
tE6.Color = VideoColors(12,:);
tI6.Color = VideoColors(13,:);
tI6L.Color = VideoColors(14,:);
tE5B.Color = VideoColors(8,:);
tE5R.Color = VideoColors(9,:);
tI5.Color = VideoColors(10,:);
tI5L.Color = VideoColors(11,:);
tE4.Color = VideoColors(5,:);
tI4.Color = VideoColors(6,:);
tI4L.Color = VideoColors(7,:);
tE2.Color = VideoColors(1,:);
tE2B.Color = VideoColors(2,:);
tI2.Color = VideoColors(3,:);
tI2L.Color = VideoColors(4,:);
end


if(savepdf)
    set(h4, 'Color', 'w');
    export_fig([CurrentSaveDirectory 'AllConcentrations.pdf'], '-pdf', '-opengl', '-a1', '-q101')
end




end