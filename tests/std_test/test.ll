target triple = "x86_64-pc-linux-gnu"

declare void @"_PLUMMET$print"(i8*)
declare i8* @"_PLUMMET$input"()

@.str = private unnamed_addr constant [27 x i8] c"Hello, what is your name? \00", align 1
@.str.1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

define i32 @main() {
entry:
	%0 = getelementptr inbounds [27 x i8], [27 x i8]* @.str, i32 0, i32 0
	call void @"_PLUMMET$print"(i8* %0)

	%1 = call i8* @"_PLUMMET$input"()

	%2 = getelementptr inbounds [2 x i8], [2 x i8]* @.str.1, i32 0, i32 0

	call void @"_PLUMMET$print"(i8* %1)
	call void @"_PLUMMET$print"(i8* %2)

	ret i32 0
}
