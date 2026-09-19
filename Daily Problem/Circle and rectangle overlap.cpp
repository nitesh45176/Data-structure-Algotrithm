Circle and Rectangle Overlap
Problem

Given a circle and a rectangle, determine whether the circle and rectangle overlap.

You are given:

Circle
(radius, xCenter, yCenter)
Rectangle
(x1, y1) → bottom-left corner
(x2, y2) → top-right corner

Return:

true

if the circle and rectangle overlap, otherwise:

false
Intuition

The key idea is:

Find the point on the rectangle that is closest to the center of the circle.

Then calculate the distance between:

Circle center
        ↓
Closest point on rectangle

If that distance is less than or equal to the radius, the circle overlaps the rectangle.

distance <= radius
        ↓
     overlap

Otherwise:

distance > radius
        ↓
   no overlap
Step 1: Find the Closest X Coordinate

The circle center has:

(xCenter, yCenter)

The rectangle's x-range is:

[x1, x2]

We need to find the x-coordinate of the rectangle closest to xCenter.

Case 1: Circle center is to the left of rectangle
xCenter < x1

The closest x-coordinate is:

xi = x1;
Case 2: Circle center is to the right of rectangle
xCenter > x2

The closest x-coordinate is:

xi = x2;
Case 3: Circle center is horizontally inside the rectangle
x1 <= xCenter <= x2

The closest x-coordinate is the center itself:

xi = xCenter;

So:

if(x1 > xCenter) {
    xi = x1;
}
else if(x2 < xCenter) {
    xi = x2;
}
else {
    xi = xCenter;
}
Step 2: Find the Closest Y Coordinate

Exactly the same idea applies vertically.

The rectangle's y-range is:

[y1, y2]
Center below rectangle
yCenter < y1

Closest point:

yi = y1;
Center above rectangle
yCenter > y2

Closest point:

yi = y2;
Center vertically inside rectangle
y1 <= yCenter <= y2

Closest point:

yi = yCenter;

Therefore:

if(y1 > yCenter) {
    yi = y1;
}
else if(y2 < yCenter) {
    yi = y2;
}
else {
    yi = yCenter;
}
The Closest Point

After calculating xi and yi, we have:

(xi, yi)

which is the point on/in the rectangle closest to the circle center.

For example:

              Rectangle
        ┌───────────────┐
        │               │
        │       ●       │
        │               │
        └───────────────┘
                ↑
         circle center

If the circle center is outside:

                 ● circle center
                 |
                 |
        ┌────────┼──────┐
        │        │      │
        │        ●      │
        │               │
        └───────────────┘
                 ↑
          closest point
Step 3: Calculate Distance

Using the distance formula:

distance = √((xi-xCenter)² + (yi-yCenter)²)

We could write:

int d = sqrt(
    (xi-xCenter)*(xi-xCenter) +
    (yi-yCenter)*(yi-yCenter)
);

But there is a problem with this approach.

Because d is an int, sqrt() can produce a decimal value that gets truncated.

For example:

√35 = 5.91

Stored in an integer:

5

This can produce an incorrect comparison.

Step 4: Compare Squared Distances

Instead of calculating:

distance <= radius

we compare:

distance² <= radius²

Using the distance formula:

(xi-xCenter)² + (yi-yCenter)² <= radius²

So:

int dx = xi - xCenter;
int dy = yi - yCenter;

return dx * dx + dy * dy <= radius * radius;

This avoids sqrt() completely.

Code
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        int xi;
        int yi;

        // Find closest x-coordinate
        if(x1 > xCenter) {
            xi = x1;
        }
        else if(x2 < xCenter) {
            xi = x2;
        }
        else {
            xi = xCenter;
        }

        // Find closest y-coordinate
        if(y1 > yCenter) {
            yi = y1;
        }
        else if(y2 < yCenter) {
            yi = y2;
        }
        else {
            yi = yCenter;
        }

        // Calculate squared distance
        int dx = xi - xCenter;
        int dy = yi - yCenter;

        return dx * dx + dy * dy <= radius * radius;
    }
};
Dry Run

Suppose:

radius = 2
circle center = (0, 0)

rectangle:
x1 = 3
y1 = 1
x2 = 5
y2 = 4

The rectangle is here:

        (3,4)────────(5,4)
          │            │
          │            │
          │            │
        (3,1)────────(5,1)

   ●
 (0,0)
Find xi

Since:

xCenter = 0
x1 = 3

and:

x1 > xCenter

we get:

xi = 3
Find yi

Since:

yCenter = 0
y1 = 1

we get:

yi = 1

So the closest point is:

(3,1)
Calculate squared distance
dx = 3 - 0 = 3
dy = 1 - 0 = 1

Therefore:

distance² = 3² + 1²
           = 9 + 1
           = 10

Radius:

radius² = 2² = 4

Since:

10 > 4

there is no overlap.

false
Important Edge Case

If the circle center is inside the rectangle, then:

xi = xCenter
yi = yCenter

Therefore:

dx = 0
dy = 0

and:

distance² = 0

So:

0 <= radius²

which correctly returns true.

Why This Works

The circle overlaps the rectangle if and only if the distance between the circle's center and the closest point of the rectangle is at most the radius.

So the whole problem becomes:

Circle + Rectangle
       ↓
Find closest point on rectangle
       ↓
Calculate distance from center
       ↓
Compare with radius
Complexity

We perform only a constant number of calculations.

Time
O(1)
Space
O(1)
Key Takeaway

The most important pattern here is:

For circle-rectangle intersection, find the closest point of the rectangle to the circle center and compare the squared distance with the squared radius.

Remember this formula:
(xi - xCenter)² + (yi - yCenter)² <= radius²

If true → overlap
If false → no overlap
