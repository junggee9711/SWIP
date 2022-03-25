clear;
clc;
x = linspace(0, 2*pi, 25);
y = sin(x);
y1 = cos(x);

f1 = figure('Name', '100 point');
figure(f1);
plot(x, y, 'r--', 'LineWidth', 10);
