; ModuleID = 'main.c'
source_filename = "main.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@.str = private unnamed_addr constant [14 x i8] c"Hello, World!\00", align 1
@.str.1 = private unnamed_addr constant [20 x i8] c"What is your name? \00", align 1
@.str.2 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

; Function Attrs: noinline nounwind optnone sspstrong uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8**, align 8
  %4 = alloca i8*, align 8
  store i8* getelementptr inbounds ([14 x i8], [14 x i8]* @.str, i64 0, i64 0), i8** %1, align 8
  call void @"_PLUMMET$print"(i8* noundef getelementptr inbounds ([20 x i8], [20 x i8]* @.str.1, i64 0, i64 0))
  %5 = call i8* (...) @"_PLUMMET$input"()
  store i8* %5, i8** %2, align 8
  %6 = load i8*, i8** %2, align 8
  %7 = call i8** @"_PLUMMET$split"(i8* noundef %6, i8 noundef signext 32)
  store i8** %7, i8*** %3, align 8
  %8 = load i8**, i8*** %3, align 8
  %9 = call i8* @"_PLUMMET$join"(i8** noundef %8, i8 noundef signext 32)
  store i8* %9, i8** %4, align 8
  %10 = load i8*, i8** %4, align 8
  call void @"_PLUMMET$print"(i8* noundef %10)
  call void @"_PLUMMET$print"(i8* noundef getelementptr inbounds ([2 x i8], [2 x i8]* @.str.2, i64 0, i64 0))
  ret i32 0
}

declare void @"_PLUMMET$print"(i8* noundef) #1

declare i8* @"_PLUMMET$input"(...) #1

declare i8** @"_PLUMMET$split"(i8* noundef, i8 noundef signext) #1

declare i8* @"_PLUMMET$join"(i8** noundef, i8 noundef signext) #1

attributes #0 = { noinline nounwind optnone sspstrong uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 14.0.6"}
