#ifndef CAPTURE_H
#define CAPTURE_H

void handleCaptureCircle(Assets assets, Vector2 circlePosition, float innerRadius, float speed, float *angle);
bool handleUpdateCaptureCircle(Vector2 circlePosition, float innerRadius, float *angle);

#endif