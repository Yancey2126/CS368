clear 
% clear all variables from the workspace so 
% they dont't collide with other names
clc
% clear the screen


x = 0:2*pi/200:2*pi;
y_sin = sin(x);
y_exp = exp(y_sin);

% three choices
% comment
% disp('requires', 'a', 'simple', 'string')
% delete the bad code 
% delete from the command history

%% plot sin(x)
% single plot
figure % open a new figure window
plot (x, y_sin, 'kd') % balack diamond
title( 'sin(x)' )
xlabel( 'x' )
ylabel( 'sin(x)' )

%% exp(sin(x))
% second simple plot
figure
plot(x, y_exp, 'ro:')
title( ' exp(sin(x))' )

%% both plots
% two different ways
figure
plot(x, y_sin, 'kd', x, y_exp, 'ro:')
title( 'both plots' )

% both plots using hold on
figure
clf % clear the old figure
hold on
plot (x, y_sin, 'kd')
plot(x, y_exp, 'ro:')
title( 'both plots using hold on and hold off' )
legend( 'sin(x)', 'exp(sin(x))')
hold off

%% PUBLISHING SCRIPTS
% 

%% as a pdf




