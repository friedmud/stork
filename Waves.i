[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 10
  ny = 10
  xmax = 10
  ymax = 10
  elem_type = QUAD4
  uniform_refine = 4
[]

[Variables]
  [./v]
    order = FIRST
    family = LAGRANGE
  [../]
  [./h]
    order = FIRST
    family = LAGRANGE
  [../]
[]

[Kernels]
  [./h_diffusion]
    type = Diffusion
    variable = h
  [../]
  [./v_dot]
    type = CoupledImplicitEuler
    variable = h
    v = v
  [../]

  [./v_constant]
    type = ValueKernel
    variable = v
  [../]
  [./h_dot]
    type = CoupledImplicitEuler
    variable = v
    v = h
  [../]
[]

[Executioner]
  #petsc_options_iname = '-pc_type -ksp_grmres_restart -sub_ksp_type -sub_pc_type -pc_asm_overlap'
  #petsc_options_value = 'asm      301                 preonly       lu           1'

  #petsc_options_iname = '-pc_type -ksp_grmres_restart'
  #petsc_options_value = 'lu       301   '
  
  petsc_options_iname = '-pc_type -ksp_grmres_restart -sub_ksp_type -sub_pc_type -pc_asm_overlap'
  petsc_options_value = 'asm         31   preonly   lu      1'

  #petsc_options_iname = '-pc_type -pc_hypre_type -ksp_gmres_restart'
  #petsc_options_value = 'hypre    boomeramg      301'
  
  type = Transient
  dt = 0.1
  l_max_its = 300
  solve_type = PJFNK
  l_tol = 1e-4
  end_time = 20.0
  scheme = bdf2

  #[./TimeStepper]
  #  type = IterationAdaptiveDT
  #  dt = 0.1 #Initial time step
  #  growth_factor = 1.5 #Maximum about by which the time step and increase each step
  #  optimal_iterations = 60 #Time step will change to maintain this number of nonlinear iterations
  #[../]

  #[./Adaptivity]
  #  # Block that turns on mesh adaptivity. Note that mesh will never coarsen beyond initial mesh (before uniform refinement)
  #  initial_adaptivity = 3 # Number of times mesh is adapted to initial condition
  #  refine_fraction = 0.7 # Fraction of high error that will be refined
  #  coarsen_fraction = 0.05 # Fraction of low error that will coarsened
  #  max_h_level = 4 # Max number of refinements used, starting from initial mesh (before uniform refinement)
  #  weight_names = 'h v' #This combo of values makes the mesh adapt to c but not w
  #  weight_values = '1.0 0.0'
  #[../]
[]

[Outputs]
  output_initial = true
  exodus = true
  [./console]
    type = Console
    perf_log = true
    #linear_residuals = true
  [../]
[]

[ICs]
  [./lift]
    y2 = 5
    y1 = 3
    inside = 0.1
    x2 = 5
    variable = h
    x1 = 3
    type = BoundingBoxIC
    block = 0
  [../]
[]
