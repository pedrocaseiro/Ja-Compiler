; ModuleID = 'code_generation.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [7 x i8] c"daniel\00", align 1
@.str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str.2 = private unnamed_addr constant [7 x i8] c"%.16E\0A\00", align 1
@.str.3 = private unnamed_addr constant [6 x i8] c"true\0A\00", align 1
@.str.4 = private unnamed_addr constant [7 x i8] c"false\0A\00", align 1
@.str.5 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@.str.6 = private unnamed_addr constant [7 x i8] c"sfasf\0A\00", align 1
@.str.7 = private unnamed_addr constant [26 x i8] c"ola\0Dola\0Cola\09ola\5Cola\5C\5Cola\0A\00", align 1
@h = common global i32 0, align 4

; Function Attrs: nounwind uwtable
define i32 @main(i32 %argc, i8** %argv) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i8**, align 8
  %l = alloca i32, align 4
  %y = alloca i32, align 4
  %t = alloca double, align 8
  %b = alloca i8, align 1
  %u = alloca i8*, align 8
  store i32 0, i32* %1, align 4
  store i32 %argc, i32* %2, align 4
  store i8** %argv, i8*** %3, align 8
  store i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str, i32 0, i32 0), i8** %u, align 8
  store double 4.400000e+00, double* %t, align 8
  store i8 1, i8* %b, align 1
  store i32 5, i32* %l, align 4
  %4 = load i32, i32* %l, align 4
  %5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i32 0, i32 0), i32 %4)
  %6 = load double, double* %t, align 8
  %7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.2, i32 0, i32 0), double %6)
  %8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.3, i32 0, i32 0))
  %9 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.4, i32 0, i32 0))
  %10 = load i8*, i8** %u, align 8
  %11 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.5, i32 0, i32 0), i8* %10)
  %12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.6, i32 0, i32 0))
  %13 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str.7, i32 0, i32 0))
  ret i32 0
}

declare i32 @printf(i8*, ...) #1

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.1-12~bpo8+1 (tags/RELEASE_381/final)"}
