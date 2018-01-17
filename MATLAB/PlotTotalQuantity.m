function PlotTotalQuantity(AllNumbers, Load_Directories, Save_Directory, savepdf)
FontSizeAll = 18;
MultiplierPDF = 1;
FontSizeAll = FontSizeAll*MultiplierPDF;
for CurrentExperiment = 1:prod(AllNumbers)
	CurrentDirectory = Load_Directories{CurrentExperiment};
	load([CurrentDirectory 'Everything.mat'], 'TotalQuantitySmall', 'dingcounter', 'dt', 'PropagationTimesteps', 'VideoColors' );
	dingcounters(CurrentExperiment) = dingcounter;
	TotalQuantitySmallAll{CurrentExperiment} = TotalQuantitySmall;
end

for ParameterSet = 1:prod(AllNumbers(1:end-2))
	dingcounter = max(dingcounters((ParameterSet-1)*AllNumbers(end-1)+1:ParameterSet*AllNumbers(end-1)));
	l = dingcounter-1;
	for seed = 1:AllNumbers(end-1)
		CurrentExperiment = (ParameterSet-1)*AllNumbers(end-1)+seed;
		TotalQuantitySmallAll{CurrentExperiment}(1,min(end+1,l):l) = TotalQuantitySmallAll{CurrentExperiment}(1,end);
	end
end


for ParameterSet = 1:prod(AllNumbers(1:end-2))
    dingcounter = max(dingcounters((ParameterSet-1)*AllNumbers(end-1)+1:ParameterSet*AllNumbers(end-1)));
    final = dt*(PropagationTimesteps*(dingcounter-1)+2);
    l = dingcounter-1;
    
    width = 30*MultiplierPDF;
    height = 15*MultiplierPDF;
    h1 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],...
           'PaperUnits','centimeters',...
           'PaperSize',[width height],...
           'PaperPositionMode','auto',...
           'InvertHardcopy', 'on',...
           'Renderer','painters'...   
       );
   hold on;
   for seed = 1:AllNumbers(end-1)
	   CurrentExperiment = (ParameterSet-1)*AllNumbers(end-1)+seed;
       if(seed == 1)
           ColorConcentrationPlot = [0 0 0];
       elseif(seed == 2)
           ColorConcentrationPlot = [0.5 0.5 0.5];
       elseif(seed > 2)
           ColorConcentrationPlot = VideoColors(seed-2,:);
       end
       if(seed > 2)
           ColorConcentrationPlot = 2*ColorConcentrationPlot/256;
       end
       
%        subplot(1,2,1);
	   plot(0:final/(l-1):final, TotalQuantitySmallAll{CurrentExperiment},'Color',ColorConcentrationPlot);
       hold on;
       set(gca,'FontSize',FontSizeAll)
       xlabel('time', 'FontSize', FontSizeAll);
       ylabel('Total Protein Quantity', 'FontSize', FontSizeAll);
	   if(seed == AllNumbers(end-1))		   
		   h_legend=legend('All column 1','L4, L6 column 1','single L2RS', 'single L2IB','single L2FS','single L2LTS','single L4RS','single L4FS','single L4LTS','single L5RS', 'single L5IB','single L5FS','single L5LTS','single L6RS','single L6FS','single L6LTS','Location','northwest');
		   set(h_legend,'FontSize',12);
	   end
%        subplot(1,2,2);semilogy(0:final/(l-1):final, TotalConcentrationsSmallAll{experiment},'Color',ColorConcentrationPlot);
%        hold on;
%        set(gca,'FontSize',FontSizeAll)
%        title('b. Logarithmic Scale Total Protein Quantity','FontSize',FontSizeAll)
%        xlabel('time','FontSize',FontSizeAll)
%        ylabel('Total Protein Quantity','FontSize',FontSizeAll)
% 	   if(seed == allnumbers(end))
% 		   h_legend=legend('All column 1','L4, L6 column 1','single L2RS', 'single L2IB','single L2FS','single L2LTS','single L4RS','single L4FS','single L4LTS','single L5RS', 'single L5IB','single L5FS','single L5LTS','single L6RS','single L6FS','single L6LTS','Location','southeast');
% 		   set(h_legend,'FontSize',12);
% 	   end
   end
   hold off;
   
   if(savepdf)
		set(gcf, 'Color', 'w');
		export_fig([Save_Directory 'TotalConcentration' num2str(ParameterSet)], '-pdf', '-painters', '-a1', '-q101')
    end
end

end

