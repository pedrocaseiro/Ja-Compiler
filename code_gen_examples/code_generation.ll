; ModuleID = 'code_generation.c'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.12.0"

; Function Attrs: nounwind ssp uwtable
define i32 @main(i32 %argc, i8** %argv) #0 {
entry:
  %retval = alloca i32, align 4
  %argc.addr = alloca i32, align 4
  %argv.addr = alloca i8**, align 8
  store i32 0, i32* %retval, align 4
  store i32 %argc, i32* %argc.addr, align 4
  store i8** %argv, i8*** %argv.addr, align 8
  ret i32 0
}

; Function Attrs: nounwind ssp uwtable
define void @teralul() #0 {
entry:
  ret void
}

; Function Attrs: nounwind ssp uwtable
define double @cg() #0 {
entry:
  %a = alloca double, align 8
  store double 5.500000e+00, double* %a, align 8
  %0 = load double, double* %a, align 8
  ret double %0
}

; Function Attrs: nounwind ssp uwtable
define double @cl() #0 {
entry:
  %a = alloca i32, align 4
  store i32 3, i32* %a, align 4
  %0 = load i32, i32* %a, align 4
  %conv = sitofp i32 %0 to double
  ret double %conv
}

attributes #0 = { nounwind ssp uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"PIC Level", i32 2}
!1 = !{!"clang version 3.8.1 (tags/RELEASE_381/final)"}
