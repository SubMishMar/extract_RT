function ry = rotny(theta)

theta = theta * pi/180;

c = cos(theta);
s = sin(theta);

ry = [c  0   s;
      0  1   0;
     -s  0   c];
end