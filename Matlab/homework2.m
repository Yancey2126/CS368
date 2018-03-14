%% CS368 Spring 2017 Homework Assignment 2
% * Name: YANG CHEN
% * Due Date: Friday, February 17 by 11:59 pm


%% Problem 1: Creating a tip table
% Create and display a matrix with four columns:
%
% * column 1 contains bill totals from $5 to $100 in increments of $5
% * column 2 contains the tip amount if the tip is 15% of the bill
% * column 3 contains the tip amount if the tip is 18% of the bill
% * column 4 contains the tip amount if the tip is 20% of the bill
clear
format bank  % this will format money values nicely

bills = [5:5:100]';
tiptable = [bills, bills * 0.15, bills * 0.18, bills * 0.20];
disp(tiptable);

format short % change formatting back to default setting


%% Problem 2:  Density of freshwater
% Compute the density of freshwater as a function of temperature
% 
% * Temperature at 40 °F, 68 °F, and 100 °F
clear

temperF = [40, 68, 100];
temperC = 5/9 * (temperF - 32);
rho = 5.5289 * 10^(-8) * temperC.^3 - 8.5016 * 10^(-6) * temperC.^2 ...
+ 6.5622 * 10^(-5) * temperC + 0.99987;

disp(['Freshwater density is ', num2str(rho(1)), ' at ', num2str(temperF(1)), ' F'])
disp(['Freshwater density is ', num2str(rho(2)), ' at ', num2str(temperF(2)), ' F'])
disp(['Freshwater density is ', num2str(rho(3)), ' at ', num2str(temperF(3)), ' F'])


%% Problem 3 (8 points) : Distance to horizon
% Plot the distance to the horizon vs the height of a hill 
% for hill heights from 0 to 10,000 feet on Earth and Mars on one plot figure
clear

rE = 7926 / 2 * 5280;
rM = 4217 / 2 * 5280;
h = 0 : 10 : 10000;

dE = sqrt(2 * rE * h + h.^2);
dM = sqrt(2 * rM * h + h.^2);

plot(dE, h, 'b--', dM, h, 'r');
title('The distance to the horizon from a location on Earth and Mars(feet)');
xlabel('The height of the hill(feet)');
ylabel('Distance to the horizon(feet)');

