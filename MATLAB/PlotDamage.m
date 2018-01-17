function PlotDamage( CurrentLoadDirectory, CurrentSaveDirectory, savepdf)
VideoDamage = dlmread([CurrentLoadDirectory 'VideoDamage.dat']);
CellColumns = dlmread([CurrentLoadDirectory 'SaveCellColumns.dat']);
CellTypes = dlmread([CurrentLoadDirectory 'SaveCellTypes.dat']);
VideoColors = dlmread('VideoColors.dat');
VideoColors = double(uint8(2*VideoColors))/256;
%CellColumns(1) up to CellColumns(180) are the same cell type... likewise
%for every pair: 181-255, 256-294, etc.
ChangeCellTypes = [1 180 181 255 256 294 295 345 346 540 541 615 616 654 655 744 745 804 805 846 847 1272 1273 1296 1297 1371 1372 1410];

for i = size(VideoDamage,2):-1:1
    if(nnz(VideoDamage(:,i)) > 0)
        stopat = i;
        break;
    end
end

VideoDamage = VideoDamage(:,1:stopat);

%fig 4
FontSizeAll = 9;
width = 10;
height = 10;
h4 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],...
    'PaperUnits','centimeters',...
    'PaperSize',[width height],...
    'PaperPositionMode','auto',...
    'InvertHardcopy', 'on',...
    'Renderer','opengl'...
    );
imagesc(linspace(0,10*size(VideoDamage,2), size(VideoDamage,2)), 1:size(VideoDamage,1), VideoDamage); 

set(gca,'FontSize',FontSizeAll);xlabel('Time','FontSize',FontSizeAll);set(gcf, 'Color', 'w');set(gca,'ycolor',[1 1 1 ]); set(gca,'ytick',[]);colorbar; colormap hot;

for i = ChangeCellTypes; line(xlim+[-10 0],[1 1]*i + 0.5,'color','k','LineWidth',0.1,'Clipping','off');  end
i=1;tE6   = text(-0.15*10*size(VideoDamage,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'E6RS','FontSize',FontSizeAll);
i=2;tI6   = text(-0.15*10*size(VideoDamage,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'I6FS','FontSize',FontSizeAll);
i=3;tI6L  = text(-0.15*10*size(VideoDamage,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'I6LTS','FontSize',FontSizeAll);
i=4;tE5B  = text(-0.15*10*size(VideoDamage,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'E5IB','FontSize',FontSizeAll);
i=5;tE5R  = text(-0.15*10*size(VideoDamage,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'E5RS','FontSize',FontSizeAll);
i=6;tI5   = text(-0.15*10*size(VideoDamage,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'I5FS','FontSize',FontSizeAll);
i=7;tI5L  = text(-0.15*10*size(VideoDamage,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'I5LTS','FontSize',FontSizeAll);
i=8;tE4   = text(-0.15*10*size(VideoDamage,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'E4RS','FontSize',FontSizeAll);
i=9;tI4   = text(-0.15*10*size(VideoDamage,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'I4FS','FontSize',FontSizeAll);
i=10;tI4L = text(-0.15*10*size(VideoDamage,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'I4LTS','FontSize',FontSizeAll);
i=11;tE2  = text(-0.15*10*size(VideoDamage,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'E2RS','FontSize',FontSizeAll);
i=12;tE2B = text(-0.15*10*size(VideoDamage,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'E2IB','FontSize',FontSizeAll);
i=13;tI2  = text(-0.15*10*size(VideoDamage,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'I2FS','FontSize',FontSizeAll);
i=14;tI2L = text(-0.15*10*size(VideoDamage,2),ceil(mean(ChangeCellTypes(2*i-1:2*i))),'I2LTS','FontSize',FontSizeAll);
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

if(savepdf)
    set(h4, 'Color', 'w');
    export_fig([CurrentSaveDirectory 'DamageTime.pdf'], '-pdf', '-opengl', '-a1', '-q101')
end



















% width = 20;
% height = 20;
% h4 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],...
%     'PaperUnits','centimeters',...
%     'PaperSize',[width height],...
%     'PaperPositionMode','auto',...
%     'InvertHardcopy', 'on',...
%     'Renderer','opengl'...
%     );
% imagesc(VideoDamage); colorbar; colormap hot; xlabel('Time','FontSize',FontSizeAll);ylabel('Neuron ID','FontSize',FontSizeAll);	set(gcf, 'Color', 'w');colorbar; colormap hot;
% set(gca,'FontSize',FontSizeAll)
% set(gcf, 'Color', 'w');
% 
% if(savepdf)
%     set(h4, 'Color', 'w');
%     export_fig([CurrentSaveDirectory 'DamageTime2.pdf'], '-pdf', '-opengl', '-a1', '-q101')
% end
end