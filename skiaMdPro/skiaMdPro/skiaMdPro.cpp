#include "include/core/SkBitmap.h"
//#include "include/codec/SkDevice.h"
#include "include/core/SkPaint.h"
#include "include/core/SkRect.h"
#include "include/core/SkImageEncoder.h"
#include "include/core/SkTypeface.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkTypeface.h"
#include "include/core/SkFont.h"
#include "include/core/SkTextBlob.h"
#include "include/core/SkPath.h"

const char* pText = "Hello world!";

int main()
{
	const int width = 1000;
	const int height = 1000;

	SkBitmap bitmap;
	SkImageInfo ii = SkImageInfo::Make(1000, 1000, kBGRA_8888_SkColorType, kPremul_SkAlphaType);
	bitmap.allocPixels(ii, ii.minRowBytes());

	SkPaint paint;
	paint.setStyle(SkPaint::kStroke_Style);
	paint.setColor(0xff1f78b4);
	paint.setStrokeWidth(8);

	bitmap.allocPixels();
	SkCanvas canvas(bitmap);
	canvas.clear(0x00000000);// 背景为透明色

	if (0) {
		SkRect rc;
		rc.fLeft = 123;
		rc.fTop = 0;
		rc.fRight = 222;
		rc.fBottom = 50;
		canvas.drawOval(rc, paint);
	}

	if (0) {
		//测试奇偶填充效果1
		SkPath path;

		path.addCircle(200, 200, 70);
		path.addCircle(300, 200, 70);
		path.addCircle(250, 250, 70);

		paint.setAntiAlias(true);//抗锯齿
		paint.setStyle(SkPaint::kFill_Style);
		paint.setStrokeWidth(1);
		paint.setColor(SK_ColorBLACK);
		canvas.drawPath(path, paint);
	}
	if (0) {
		//测试奇偶填充效果2
		SkPath path, path1, path2, path3;
		SkPoint pt[11];
		pt[0] = SkPoint::Make(200, 400);
		pt[1] = SkPoint::Make(400, 300);
		pt[2] = SkPoint::Make(600, 300);
		pt[3] = SkPoint::Make(800, 400);
		pt[4] = SkPoint::Make(700, 800);
		pt[5] = SkPoint::Make(600, 600);
		pt[6] = SkPoint::Make(500, 600);
		pt[7] = SkPoint::Make(500, 400);
		pt[8] = SkPoint::Make(600, 300);
		pt[9] = SkPoint::Make(800, 200);

		//一条完整path
		if (0) {
			path.moveTo(pt[0]);
			path.cubicTo(pt[1], pt[2], pt[3]);
			path.cubicTo(pt[4], pt[5], pt[6]);
			path.cubicTo(pt[7], pt[8], pt[9]);
			path.lineTo(pt[3]);
		}

		//三条path加进去
		if (1) {
			path1.moveTo(pt[0]).cubicTo(pt[1], pt[2], pt[3]);
			path2.moveTo(pt[3]).cubicTo(pt[4], pt[5], pt[6]);
			path3.moveTo(pt[6]).cubicTo(pt[7], pt[8], pt[9]);
			path.addPath(path1).addPath(path2).addPath(path3);
		}

		paint.setAntiAlias(true);//抗锯齿
		paint.setStyle(SkPaint::kStrokeAndFill_Style);
		paint.setStrokeWidth(1);
		paint.setColor(SK_ColorBLACK);
		canvas.drawPath(path, paint);
	}

	if (0) {
		//测试winding填充效果
		//两个矩形，顺逆时针
		SkPath path, path1, path2, path3;
		SkPoint pt[8];
		pt[0] = SkPoint::Make(200, 500);
		pt[1] = SkPoint::Make(400, 300);
		pt[2] = SkPoint::Make(600, 500);
		pt[3] = SkPoint::Make(400, 700);
		pt[4] = SkPoint::Make(400, 500);
		pt[5] = SkPoint::Make(600, 300);
		pt[6] = SkPoint::Make(800, 500);
		pt[7] = SkPoint::Make(600, 700);

		//顺时针path
		path1.moveTo(pt[0]).lineTo(pt[1]).lineTo(pt[2]).lineTo(pt[3]).close();

		//逆时针path
		path2.moveTo(pt[4]).lineTo(pt[7]).lineTo(pt[6]).lineTo(pt[5]).close();

		path.addPath(path1).addPath(path2);

		path.setFillType(SkPathFillType::kWinding);

		paint.setAntiAlias(true);//抗锯齿
		paint.setStyle(SkPaint::kFill_Style);
		//paint.setStyle(SkPaint::kStroke_Style);
		paint.setStrokeWidth(1);
		paint.setColor(SK_ColorBLACK);
		canvas.drawPath(path, paint);
	}

	if (0) {
		//测试不闭合path绘制问题
		SkPath path, path1, path2, path3;
		SkPoint pt[6];
		pt[0] = SkPoint::Make(300, 200);
		pt[1] = SkPoint::Make(500, 200);
		pt[2] = SkPoint::Make(200, 500);
		pt[3] = SkPoint::Make(600, 500);
		pt[4] = SkPoint::Make(200, 700);
		pt[5] = SkPoint::Make(600, 700);

		path.moveTo(pt[0]).lineTo(pt[5]);
		path.moveTo(pt[1]).lineTo(pt[4]); //path1.moveTo(pt[1]).lineTo(pt[4]);
		path.moveTo(pt[2]).lineTo(pt[3]); //path2.moveTo(pt[1]).lineTo(pt[4]);

		//path.addPath(path1).addPath(path2);

		path.setFillType(SkPathFillType::kWinding);

		paint.setAntiAlias(true);//抗锯齿
		paint.setStyle(SkPaint::kStrokeAndFill_Style);
		paint.setStrokeWidth(1);
		paint.setColor(SK_ColorBLACK);
		canvas.drawPath(path, paint);
	}

	if (1) {
		//测试不闭合path绘制问题2
		SkPath path, path1, path2, path3;
		SkPoint pt[6];
		pt[0] = SkPoint::Make(200, 200);
		pt[1] = SkPoint::Make(400, 200);
		pt[2] = SkPoint::Make(600, 200);
		pt[3] = SkPoint::Make(200, 600);
		pt[4] = SkPoint::Make(400, 600);
		pt[5] = SkPoint::Make(600, 600);

		path.moveTo(pt[0]).lineTo(pt[4]).lineTo(pt[2]);
		path1.moveTo(pt[3]).lineTo(pt[1]).lineTo(pt[5]);

		path.setFillType(SkPathFillType::kWinding);
		path1.setFillType(SkPathFillType::kWinding);

		paint.setAntiAlias(true);//抗锯齿
		paint.setStyle(SkPaint::kStrokeAndFill_Style);
		paint.setStrokeWidth(1);
		paint.setColor(SK_ColorBLACK);
		canvas.drawPath(path, paint);
		canvas.drawPath(path1, paint);
	}

	if (0) {
		//画贝塞尔曲线
		SkPath path;
		SkPoint pt[20];

		pt[0].set(100, 100);
		pt[1].set(200, 80);
		pt[2].set(300, 80);
		pt[3].set(400, 100);

		pt[4].set(300, 200);
		pt[5].set(200, 300);
		pt[6].set(100, 300);

		path.moveTo(pt[0]);
		//二次贝塞尔曲线
		//path.quadTo(pt1, pt2);
		//三次贝塞尔曲线
		path.cubicTo(pt[1], pt[2], pt[3]);
		path.cubicTo(pt[4], pt[5], pt[6]);

		//path.moveTo(pt[0]);
		//path.lineTo(pt[3]);
		//path.close();
		paint.setAntiAlias(true);//抗锯齿
		paint.setStyle(SkPaint::kFill_Style);
		paint.setStrokeWidth(1);
		paint.setColor(SK_ColorBLACK);
		canvas.drawPath(path, paint);
		//贝塞尔点
		paint.setColor(SK_ColorRED);
		canvas.drawCircle(pt[0].x(), pt[0].y(), 4, paint);
		canvas.drawCircle(pt[1].x(), pt[1].y(), 4, paint);
		canvas.drawCircle(pt[2].x(), pt[2].y(), 4, paint);
		canvas.drawCircle(pt[3].x(), pt[3].y(), 4, paint);
	}

	if (0) {
		//画弧线
		SkPath path;
		SkPoint pt1, pt2, pt_ctrl;
		SkPaint paint;
		pt1.set(100, 100);
		pt_ctrl.set(180, 250);
		pt2.set(300, 300);
		for (float i = 1; i < 20; i += 1) {
			SkPath tmp;
			tmp.moveTo(pt1);
			tmp.conicTo(pt_ctrl, pt2, i);
			path.addPath(tmp);
		}
		path.close();
		paint.setAntiAlias(true);//抗锯齿
		paint.setStyle(SkPaint::kStroke_Style);
		paint.setStrokeWidth(1);
		paint.setColor(SK_ColorBLACK);
		canvas.drawPath(path, paint);
	}

	SkFILEWStream stream("./test.jpg");
	SkEncodeImage(&stream, bitmap, SkEncodedImageFormat::kPNG, 100);

	return 0;
}