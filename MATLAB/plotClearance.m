close all;
FontSizeAll = 24;
width = 50;
height = 20;
h2 = figure('visible','on','Units','centimeters', 'Position',[0 0 width height],...
		'PaperUnits','centimeters',...
		'PaperSize',[width height],...
		'PaperPositionMode','auto',...
		'InvertHardcopy', 'on',...
		'Renderer','painters'...
		);
set(gca,'FontSize',FontSizeAll)
set(gcf, 'Color', 'w');




Cnn = [0.01 0.05 0.1 0.2];
for i = 1:numel(Cnn)
a = log(1+(exp(1)-1)*(0:0.02:1)/Cnn(i));
if i == 1
	plot(0:0.02:1,a,'k-', 'LineWidth', 2); hold on;
elseif i == 2
	plot(0:0.02:1,a,'k--', 'LineWidth', 2); hold on;
elseif i == 3
	plot(0:0.02:1,a,'k-.', 'LineWidth', 2); hold on;
elseif i == 4
	plot(0:0.02:1,a,'k:', 'LineWidth', 2); hold off;
end
h_legend = legend('C_{nn} = 0.01', 'C_{nn} = 0.05', 'C_{nn} = 0.1', 'C_{nn} = 0.2', 'location', 'NorthWest', 'FontSize', '18');
set(h_legend,'FontSize',FontSizeAll);
hxlabel = xlabel('C_{n_{i,j}}^t');
set(hxlabel, 'FontSize', FontSizeAll);
hylabel = ylabel('c_{n_{i,j}}^t');
set(hylabel, 'FontSize', FontSizeAll);
set(gca, 'fontsize', FontSizeAll);
end

export_fig('ClearanceLogs', '-pdf', '-painters', '-a1', '-q101')
