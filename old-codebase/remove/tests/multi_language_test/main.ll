; ModuleID = 'main.ll'
source_filename = "main.ll"
target triple = "x86_64-pc-linux-gnu"

declare i32 @addNums(i32, i32)

declare i32 @readInt()

declare i32 @printInt(i32)

define i32 @main() {
entry:
  %0 = call i32 @readInt()
  %1 = call i32 @readInt()
  %2 = call i32 @addNums(i32 %0, i32 %1)
  %3 = call i32 @printInt(i32 %2)
  ret i32 0
}
