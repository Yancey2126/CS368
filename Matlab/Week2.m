% STRINGS are 1-d matrices(vectors)
color1='red';
color2='yellow';
color1(3);

mix_colors = [color1, '_', color2];
mix_colors(5:end);

disp('adding an apostrophe '' is easy');
disp(['requires ', 'only ', num2str(1), ' string']);

% OPERATORS
A = [1,2;3,4];
B = [3,4;5,6];
A + B;

R = [1 33 4 2 5];
S=[3, 5, 3, 6, 4];
S + R;
R .* S; % Pariwaise multiplication instead of matrix multiplication


% PLOTTING
% plot 
plot( [1 3 5 2 7], [1 4 8 9 2], 'ro:');

x = 1:1000;
y = x.^2;
length(x);
plot(x, y);

x = 0:2*pi/200:2*pi;
y = sinx(x);
y_exp = exp(y);
plot(x,y,'b',x,y_exp,'k');
title('sin(x)');
xlabel('points');
ylabel('sin(x)');
legend('sin(x)', 'exo(sin(x))');
xmin = -3;
xmax = 3;
ymin = -6;
ymax = 6;
axis([xmin, xmax, ymin, ymax]);
